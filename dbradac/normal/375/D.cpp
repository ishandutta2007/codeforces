#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

const int MAX = 100100, LOG = 17;

struct str {
    int node, val;
    str (int node, int val) : node(node), val(val) {}
    str () {}
};

struct ev {
    int t, node, val;
    ev (int t, int node, int val) : t(t), node(node), val(val) {}
    ev () {}
} event[MAX*20];

bool operator < (ev a, ev b)
{
    return a.t > b.t;
}

struct strq {
    int node, val, ind;
} q[MAX];

bool operator < (strq a, strq b)
{
    return a.val > b.val;
}

int vr=0, brev=0;
int boj[MAX], disc[MAX], fin[MAX], lca[LOG][MAX], dub[MAX], fen[MAX], rje[MAX];
vector <int> B[MAX];
list <str> L[MAX];
vector <int> V[MAX];

bool ManjiDisc(int a, int b)
{
    return disc[a] < disc[b];
}

void Rek(int node, int prosli)
{
    int i;
    vector <int> :: iterator it;

    disc[node] = vr++;
    dub[node] = dub[prosli] + 1;

    for (lca[0][node]=prosli, i=1; i<LOG; i++)
        lca[i][node] = lca[i-1][lca[i-1][node]];

    for (it=V[node].begin(); it!=V[node].end(); it++)
        if (*it != prosli)
            Rek(*it, node);

    fin[node] = vr;
}

int brlca=0;

int Lca(int a, int b)
{
    int raz, i;

    brlca++;

    if (dub[a] > dub[b])
        swap(a, b);

    for (i=0, raz = dub[b] - dub[a]; raz; raz >>= 1, i++)
        if (raz & 1)
            b = lca[i][b];

    if (a == b)
        return a;

    for (i=LOG-1; i>=0; i--)
        if (lca[i][a] != lca[i][b]) {
            a = lca[i][a];
            b = lca[i][b];
        }

    return lca[0][a];
}

void Stavi(int pos, int val)
{
    for (pos++; pos<MAX; pos += pos & -pos)
        fen[pos] += val;
}

int Vrati(int pos)
{
    int r=0;

    for (pos++; pos; pos -= pos & -pos)
        r += fen[pos];

    return r;
}

int main()
{
    int i, j, n, brq, a, b, lc, lcl, lcr, sz;
    list <str> :: iterator it, it2, it3, ittmp;

    scanf("%d%d", &n, &brq);

    for (i=0; i<n; i++) {
        scanf("%d", &boj[i]); boj[i]--;
        B[boj[i]].push_back(i);
    }

    for (i=0; i<n-1; i++) {
        scanf("%d%d", &a, &b); a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    Rek(0, 0);

    for (i=0; i<MAX; i++) {
        sort(B[i].begin(), B[i].end(), ManjiDisc);
        for (j=0, it=L[i].begin(); (unsigned) j<B[i].size(); j++) {
            L[i].insert(it, str(B[i][j], 1));
            event[brev++] = ev(1, B[i][j], 1);
        }

        sz = L[i].size();

        for (it=L[i].begin(), it++; sz > 1; ) {
            it2 = it; it2++;
            if (it2 == L[i].end()) {
                it2 = it; it2--;
                lc = Lca(it->node, it2->node);
                event[brev++] = ev(it->val + it2->val, lc, 1);
                event[brev++] = ev(it->val, lc, -1);
                event[brev++] = ev(it2->val, lc, -1);
                L[i].insert(it, str(lc, it->val + it2->val));
                ittmp = it; ittmp--;
                L[i].erase(it); L[i].erase(it2);
                it = ittmp;
                sz--;
            }
            else {
                if (it != L[i].begin()) {
                    it3 = it; it3--;
                    lcl = Lca(it->node, it3->node);
                    lcr = Lca(it->node, it2->node);
                    if (dub[lcl] > dub[lcr]) {
                        L[i].insert(it, str(lcl, it->val + it3->val));
                        event[brev++] = ev(it->val + it3->val, lcl, 1);
                        event[brev++] = ev(it->val, lcl, -1);
                        event[brev++] = ev(it3->val, lcl, -1);
                        ittmp = it; ittmp--;
                        L[i].erase(it); L[i].erase(it3);
                        it = ittmp;
                        sz--;
                    }
                    else
                        it++;
                }
                else
                    it++;
            }
        }
    }

    sort(event, event + brev);

    for (i=0; i<brq; i++) {
        scanf("%d%d", &q[i].node, &q[i].val); q[i].node--;
        q[i].ind = i;
    }

    sort(q, q + brq);

    for (i=j=0; i<brq; i++) {
        for (; j<brev && event[j].t >= q[i].val; j++)
            Stavi(disc[event[j].node], event[j].val);

        rje[q[i].ind] = Vrati(fin[q[i].node] - 1) - Vrati(disc[q[i].node] - 1);
    }

    for (i=0; i<brq; i++)
        printf("%d\n", rje[i]);

    return 0;
}