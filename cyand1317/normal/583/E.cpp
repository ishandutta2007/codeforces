#include <cstdio>
#include <cstring>
#include <vector>
static const int MAXN = 200003;

int n;
int a[MAXN];
std::vector<int> gcd_with_n[MAXN];

int len_ct[MAXN];
bool avail[MAXN];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) gcd_with_n[gcd(n, i)].push_back(i);

    long long ans = 0;
    for (int g = 1; g < n; ++g) if (n % g == 0) {
        memset(len_ct, 0, sizeof len_ct);
        memset(avail, false, sizeof avail);
        for (int i = 0; i < g; ++i) {
            int max = -1;
            for (int j = i; j < n; j += g) if (max < a[j]) max = a[j];
            for (int j = i; j < n; j += g) if (max == a[j]) avail[j] = true;
        }
        bool all_avail = true;
        for (int i = 0; i < n; ++i) if (!avail[i]) { all_avail = false; break; }
        if (all_avail) {
            for (int i = 1; i <= n; ++i) len_ct[i] = n;
        } else {
            int i = 0, j; while (avail[i]) ++i;
            while (1) {
                j = (i + 1) % n;
                int len = 0;
                while (avail[j]) { ++len; j = (j + 1) % n; }
                for (int i = 1; i <= len; ++i) len_ct[i] += len - i + 1;
                if (j <= i) break;
                i = j;
            }
        }
        for (std::vector<int>::iterator i = gcd_with_n[g].begin();
            i != gcd_with_n[g].end(); ++i)
        {
            ans += len_ct[*i];
        }
    }

    printf("%I64d\n", ans);
    return 0;
}