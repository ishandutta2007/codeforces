#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1<<17;

struct str {
    int node;
    ll val;
    int st;
    str (int node, ll val, int st) : node(node), val(val), st(st) {}
    str () {}
};

bool operator < (str a, str b)
{
    if (a.val != b.val)
        return a.val < b.val;
    if (a.st != b.st)
        return a.st < b.st;
    return a.node < b.node;
}

struct edge {
    int node, val, st;
    edge (int node, int val, int st) : node(node), val(val), st(st) {}
    edge () {}
};

vector <edge> V[MAX];
set <str> S;
ll udalj[MAX];
int st[MAX], ima[MAX];

void Dijkstra()
{
    set <str> :: iterator its, its2;
    vector <edge> :: iterator itv;

    memset(udalj, -1, sizeof udalj);
    memset(st, -1, sizeof st);

    S.insert(str(1, 0, 0));
    udalj[1] = st[1] = 0;

    for (; !S.empty();) {
        its = S.begin();
        for (itv=V[its->node].begin(); itv!=V[its->node].end(); itv++) {
            if (udalj[itv->node] == -1 || its->val + itv->val < udalj[itv->node] ||
                its->val + itv->val == udalj[itv->node] && itv->st < st[itv->node]) {
                    its2 = S.find(str(itv->node, udalj[itv->node], st[itv->node]));
                    if (its2 != S.end())
                        S.erase(its2);
                    udalj[itv->node] = its->val + itv->val;
                    st[itv->node] = itv->st;
                    S.insert(str(itv->node, udalj[itv->node], st[itv->node]));
                }
        }

        S.erase(its);
    }
}


int main()
{
    int i, n, bre, brtr, a, b, c, rj=0;

    scanf("%d%d%d", &n, &bre, &brtr);

    for (i=0; i<bre; i++) {
        scanf("%d%d%d", &a, &b, &c);
        V[a].push_back(edge(b, c, 0));
        V[b].push_back(edge(a, c, 0));
    }

    for (i=0; i<brtr; i++) {
        scanf("%d%d", &a, &c);
        V[1].push_back(edge(a, c, 1));
        V[a].push_back(edge(1, c, 1));
        ima[a]++;
    }

    Dijkstra();

    for (i=2; i<=n; i++)
        rj += ima[i] - st[i];

    printf("%d\n", rj);

    return 0;
}