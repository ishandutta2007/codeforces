#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int n;
ll a[100005];
int f[70][100005];
ll bit;

bool is_one[100005];

bool cmp(int x, int y)
{
    return (a[x] & ((1LL << (bit+1)) - 1)) > (a[y] & ((1LL << (bit+1)) - 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i); a[i] *= 2LL;
    }
    for (int i = 0; i <= 63; i++) {
        for (int j = 0; j <= n; j++) f[i][j] = 1000000000;
    }
    f[0][0] = 0;
    /* REMEMBER TO FIX BIT BOTH HERE AND AT THE END */
    for (bit = 0; bit <= 60; bit++) {
        vector<int> idx;
        for (int i = 1; i <= n; i++) idx.push_back(i);
        sort(idx.begin(), idx.end(), cmp);
        for (int newbit = 0; newbit <= 1; newbit++) {
            int dec_cnt = 0; int nbit_cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] & (1LL << (bit+1))) {
                    if (!newbit) dec_cnt++;
                }
                is_one[i] = (newbit && !(a[i] & (1LL << (bit+1)))) || (!newbit && (a[i] & (1LL << (bit+1))));
                if (is_one[i]) nbit_cnt++;
            }
            //printf("bit %lld newbit %d: nbit_cnt = %d\n", bit, newbit, nbit_cnt);
            for (int i = 0; i <= n; i++) {
                if (i) {
                    ll num = a[idx[i - 1]];
                    if (num & (1LL << (bit+1))) {
                        if (newbit) dec_cnt++;
                    } else {
                        if (!newbit) dec_cnt++;
                    }
                    if (is_one[idx[i - 1]]) nbit_cnt--;
                    else nbit_cnt++;
                }
                //fprintf(stderr, "UPDATE %lld %d: %d (i = %d, newbit = %d, nbit_cnt = %d)\n", bit + 1, dec_cnt, f[bit][i] + nbit_cnt, i, newbit, nbit_cnt);
                f[bit+1][dec_cnt] = min(f[bit+1][dec_cnt], f[bit][i] + nbit_cnt);
            }
        }
    }
    printf("%d", f[61][0]);
    return 0;
}