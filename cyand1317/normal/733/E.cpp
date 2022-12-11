#include <cstdio>
typedef long long int64;
static const int MAXN = 1e6 + 4;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n;
char s[MAXN];
int ups_ct = 0, ups[MAXN]; int64 ups_sum[MAXN];
int dns_ct = 0, dns[MAXN]; int64 dns_sum[MAXN]; // downs

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar();
    for (int i = n; i >= -1; --i) if (i == -1 || i == n || s[i] == 'U') {
        ups[++ups_ct] = i; ups_sum[ups_ct] = ups_sum[ups_ct - 1] + ups[ups_ct];
    }
    for (int i = -1; i <= n; ++i) if (i == -1 || i == n || s[i] == 'D') {
        dns[++dns_ct] = i; dns_sum[dns_ct] = dns_sum[dns_ct - 1] + dns[dns_ct];
    }

    int ups_ptr = ups_ct, dns_ptr = 2;
    int l1, l2; int64 usum, dsum, first;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') {
            l1 = ups_ct - ups_ptr + 1;
            l2 = dns_ct - dns_ptr + 1;
            first = dns[dns_ptr] - i;
            if (l1 >= l2) { // depends on l2
                usum = (ups_sum[ups_ptr + l2 - 2] - ups_sum[ups_ptr - 1]) * 2;
                dsum = (dns_sum[dns_ptr + l2 - 1] - dns_sum[dns_ptr] + dns_sum[dns_ptr + l2 - 2] - dns_sum[dns_ptr - 1]);
            } else {        // depends on l1
                usum = (ups_sum[ups_ptr + l1 - 1] - ups_sum[ups_ptr - 1] + ups_sum[ups_ptr + l1 - 2] - ups_sum[ups_ptr - 1]);
                dsum = (dns_sum[dns_ptr + l1 - 1] - dns_sum[dns_ptr - 1] + dns_sum[dns_ptr + l1 - 1] - dns_sum[dns_ptr]);
            }
            if (ups[ups_ptr - 1] == i) --ups_ptr;
        } else /*if (s[i] == 'D')*/ {
            if (dns[dns_ptr] == i) ++dns_ptr;
            l1 = dns_ct - dns_ptr + 1;
            l2 = ups_ct - ups_ptr + 1;
            first = i - ups[ups_ptr];
            if (l1 >= l2) { // depends on l2
                dsum = (dns_sum[dns_ptr + l2 - 2] - dns_sum[dns_ptr - 1]) * 2;
                usum = (ups_sum[ups_ptr + l2 - 1] - ups_sum[ups_ptr] + ups_sum[ups_ptr + l2 - 2] - ups_sum[ups_ptr - 1]);
            } else {        // depends on l1
                dsum = (dns_sum[dns_ptr + l1 - 1] - dns_sum[dns_ptr - 1] + dns_sum[dns_ptr + l1 - 2] - dns_sum[dns_ptr - 1]);
                usum = (ups_sum[ups_ptr + l1 - 1] - ups_sum[ups_ptr - 1] + ups_sum[ups_ptr + l1 - 1] - ups_sum[ups_ptr]);
            }
        }
        printf("%I64d%c", first + dsum - usum, i == n - 1 ? '\n' : ' ');
    }

    return 0;
}