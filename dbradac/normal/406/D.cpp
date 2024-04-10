#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 100100, LOG = 17;

typedef long long ll;

ll x[MAX], y[MAX];

vector <int> S, V[MAX];
int lca[LOG][MAX], dub[MAX];

void Rek(int node, int prosli)
{
    int i;
    vector <int> :: iterator it;

    for (lca[0][node]=prosli, i=1; i<LOG; i++)
        lca[i][node] = lca[i-1][lca[i-1][node]];

    dub[node] = dub[prosli] + 1;

    for (it=V[node].begin(); it!=V[node].end(); it++)
        if (*it != prosli)
            Rek(*it, node);
}

int Lca(int a, int b)
{
    int i, raz;

    if (dub[a] > dub[b])
        swap(a, b);

    for (raz=dub[b]-dub[a], i=0; raz; raz>>=1, i++)
        if (raz & 1)
            b = lca[i][b];

    if (a == b)
        return a;

    for (i=LOG-1; i>=0; i--) {
        if (lca[i][a] != lca[i][b]) {
            a = lca[i][a];
            b = lca[i][b];
        }
    }

    return lca[0][a];
}

int Veci(double a, double b)
{
    if (a > b && abs(a - b) > 1e-11)
        return 1;
    return 0;
}

int Jed(double a, double b)
{
    return abs(a-b) < 1e-11;
}

int main()
{
    int n, i, z, pz, q, a, b;
    double a1, a2;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%I64d%I64d", &x[i], &y[i]);

    S.push_back(n-1);
    for (i=0; i<LOG; i++)
        lca[i][n-1] = n-1;

    for (i=n-2; i>=0; i--) {
        for (;;) {
            z = S.back();
            if (S.size() == 1)
                break;
            pz = S[S.size()-2];
            a1 = atan2((double) x[z] - x[i], (double) y[z] - y[i]);
            a2 = atan2((double) x[pz] - x[i], (double) y[pz] - y[i]);
            if (Veci(a1, a2))
                S.pop_back();
            else if (Jed(a1, a2)) {
                z = S.back();
                S.pop_back();
                break;
            }
            else
                break;
        }

        V[z].push_back(i);
        S.push_back(i);
    }

    Rek(n-1, n-1);

    scanf("%d", &q);

    for (i=0; i<q; i++) {
        scanf("%d%d", &a, &b); a--; b--;
        printf("%d ", Lca(a, b) + 1);
    }

    return 0;
}