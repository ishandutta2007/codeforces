#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1<<20;

struct str {
    ll pr;
    int pot;
    str (ll pr, int pot) : pr(pr), pot(pot) {}
    str () {}
};

int sito[MAX], pr[MAX], brprost;

ll k;

ll Min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

int mindexx;

void RekDiv(vector <str> &V, vector<ll> &D, ll tmp, int ind)
{
    int i;

    if (ind == (int) V.size()) {
        D.push_back(tmp);
        return;
    }

    for (i=0; i<=V[ind].pot; i++, tmp *= V[ind].pr)
        RekDiv(V, D, tmp, ind+1);
}

int ukind=MAX;
vector <str> V;
vector <ll> D[2*MAX];

int Rek(ll n, int mjesta, int dub)
{
    int i, j, kolko, z=0, indexx;
    ll pocn;

    pocn = n;

    if (mjesta <= 0)
        return 0;

    if ((ll) dub == k) {
        printf("%I64d ", n);
        return 1;
    }

    if (n < (ll) MAX)
        indexx = n;
    else
        indexx = ukind++;

    if (n == 1) {
        printf("1 ");
        return 1;
    }

    if (!D[indexx].size()) {
        V.clear();

        for (i=0; i<brprost; i++) {
            if ((ll) pr[i] * pr[i] > n)
                break;
            kolko = 0;
            for (j=1;; j++) {
                if (!(n % pr[i])) {
                    kolko = j;
                    n /= pr[i];
                }
                else
                    break;
            }
            if (kolko)
                V.push_back(str((ll) pr[i], kolko));
        }

        if (n > 1)
            V.push_back(str(n, 1));

        RekDiv(V, D[indexx], 1, 0);
        sort(D[indexx].begin(), D[indexx].end());
    }

    if (D[indexx].size() == 2) {
        for (i=0; i<Min((ll) mjesta, k-dub); i++)
            printf("1 ");
        if ((ll) mjesta - k + dub > 0)
            printf("%I64d ", pocn);
        return (int) Min(mjesta, k - dub + 1);
    }

    for (i=0; (unsigned) i<D[indexx].size(); i++) {
        z += Rek(D[indexx][i], mjesta-z, dub+1);
        if (z >= mjesta)
            return mjesta;
    }

    return z;
}

int main()
{
    int i, j;
    ll poc;

    scanf("%I64d%I64d", &poc, &k);

    for (i=2; i<MAX; i++) {
        if (!sito[i]) {
            pr[brprost++] = i;
            for (j=2*i; j<MAX; j+=i)
                sito[j] = 1;
        }
    }

    Rek(poc, 100000, 0);

    return 0;
}