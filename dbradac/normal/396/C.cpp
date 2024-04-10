#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 300100, MOD = 1000000007;

struct fen {
    int p[MAX];
    void Stavi(int pos, int val)
    {
        for (pos++; pos<MAX; pos += pos & -pos)
            p[pos] = ((ll) MOD + p[pos] + val) % MOD;

    }
    int Vrati(int pos)
    {
        int r = 0;

        for (pos++; pos; pos -= pos & -pos)
            r = (r + p[pos]) % MOD;

        return r;
    }
} k, kd, z;

vector <int> V[MAX];
int disc[MAX], fin[MAX], dub[MAX], par[MAX], t=1;

void Rek(int node)
{
    int i;

    disc[node] = t++;
    dub[node] = dub[par[node]] + 1;

    for (i=0; (unsigned) i<V[node].size(); i++)
        Rek(V[node][i]);

    fin[node] = t;
}

int main()
{
    int i, n, q, st, v, x, kk;

    scanf("%d", &n);

    for (i=1; i<n; i++) {
        scanf("%d", &par[i]); par[i]--;
        V[par[i]].push_back(i);
    }

    Rek(0);

    scanf("%d", &q);

    for (i=0; i<q; i++) {
        scanf("%d%d", &st, &v); v--;
        if (st == 1) {
            scanf("%d%d", &x, &kk);
            z.Stavi(disc[v], x);
            z.Stavi(fin[v], MOD - x);
            k.Stavi(disc[v], kk);
            k.Stavi(fin[v], MOD - kk);
            kd.Stavi(disc[v], (int) (((ll) kk * dub[v]) % MOD));
            kd.Stavi(fin[v], (int) ((((ll) -kk * dub[v]) % MOD) + MOD) % MOD);
        }
        else
            printf("%d\n", (int) (((ll) z.Vrati(disc[v]) - ((ll) dub[v] * k.Vrati(disc[v])) % MOD + kd.Vrati(disc[v]) + MOD) % MOD));
    }

    return 0;
}