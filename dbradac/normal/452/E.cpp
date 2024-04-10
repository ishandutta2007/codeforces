#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

const int MAX = 1<<19, H[2] = {3137, 101}, MODH = 2137987503, MOD = (int) (1e9) + 7, LOG = 19;

struct str {
    int ind, poz;
    str (int ind, int poz) : ind(ind), poz(poz) {}
    str () {}
} suff[MAX];

struct strs {
    int ind, val, maxx;
    strs (int ind, int val, int maxx) : ind(ind), val(val), maxx(maxx) {}
    strs () {}
};

int l[3], pref[3][MAX], lcpovi[MAX], left[MAX], right[MAX], sum[MAX], ranks[LOG][3][MAX], indexx, n;
char s[3][MAX];
stack <strs> S;

void Povecaj(strs tmp)
{
    int i, um=1;

    for (i=0; i<3; i++)
        um = ((ll) um * (pref[i][right[tmp.ind]+1] - pref[i][left[tmp.ind]-1])) % MOD;

    tmp.maxx = max(0, tmp.maxx);

    sum[tmp.maxx+1] = (sum[tmp.maxx+1] + um) % MOD;
    sum[tmp.val+1] = (sum[tmp.val+1] - um + MOD) % MOD;
}

bool Manji(str a, str b)
{
    if (!indexx)
        return s[a.ind][a.poz] < s[b.ind][b.poz];
    if (ranks[indexx-1][a.ind][a.poz] != ranks[indexx-1][b.ind][b.poz])
        return ranks[indexx-1][a.ind][a.poz] < ranks[indexx-1][b.ind][b.poz];
    return ranks[indexx-1][a.ind][a.poz+(1<<(indexx-1))] < ranks[indexx-1][b.ind][b.poz+(1<<(indexx-1))];
}

void MakeArray()
{
    int i, j, rcount;

    for (i=0, n=1; i<3; i++)
        for (j=1; j<=l[i]; j++)
            suff[n++] = str(i, j);

    for (indexx=0; indexx<LOG; indexx++) {
        sort(suff+1, suff+n, Manji);
        ranks[indexx][suff[1].ind][suff[1].poz] = rcount = 1;
        for (i=2; i<n; i++) {
            if (Manji(suff[i-1], suff[i]))
                rcount++;
            ranks[indexx][suff[i].ind][suff[i].poz] = rcount;
        }
    }
}

int Lcp(str a, str b)
{
    int i, ret;

    for (i=LOG-1, ret=0; i>=0; i--)
        if (a.poz + ret + (1 << i) <= l[a.ind] + 1 && b.poz + ret + (1 << i) <= l[b.ind] + 1 &&
            ranks[i][a.ind][a.poz+ret] == ranks[i][b.ind][b.poz+ret])
                ret += 1 << i;
    return ret;
}

int main()
{
    int i, j, minl;
    strs tmp;

    for (i=0; i<3; i++) {
        scanf("%s", s[i]+1);
        l[i] = strlen(s[i]+1);
    }

    MakeArray();

    for (i=1; i<n; i++) {
        for (j=0; j<3; j++)
            pref[j][i] = pref[j][i-1];
        pref[suff[i].ind][i]++;
    }

    for (i=1; i<n-1; i++)
        lcpovi[i] = Lcp(suff[i], suff[i+1]);

    S.push(strs(0, -1, 0));

    for (i=1; i<n-1; i++) {
        for (;;) {
            tmp = S.top();
            if (tmp.val > lcpovi[i]) {
                right[tmp.ind] = i - 1;
                tmp.maxx = max(tmp.maxx, lcpovi[i]);
                Povecaj(tmp);
                S.pop();
            }
            else if (tmp.val == lcpovi[i]) {
                left[i] = left[tmp.ind];
                left[tmp.ind] = right[tmp.ind] = 1;
                S.pop();
                S.push(strs(i, lcpovi[i], tmp.maxx));
                break;
            }
            else {
                left[i] = tmp.ind + 1;
                S.push(strs(i, lcpovi[i], tmp.val));
                break;
            }
        }
    }

    for (; !S.empty();) {
        tmp = S.top();
        right[tmp.ind] = n - 2;
        if (tmp.val > 0)
            Povecaj(tmp);
        S.pop();
    }

    minl = min(min(l[0], l[1]), l[2]);

    for (i=2; i<=minl; i++)
        sum[i] = (sum[i] + sum[i-1]) % MOD;

    for (i=1; i<=minl; i++)
        printf("%d ", sum[i]);
    printf("\n");

    return 0;
}