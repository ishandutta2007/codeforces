#include <stdio.h>
#define MAXN 100003
#define DIVIDOR 1000000007
typedef enum {
    DNA_A = 0, DNA_C, DNA_G, DNA_T, DNA_NUM_TYPES
} DNA;

int max(int a, int b)
{ return a > b ? a : b; }
int max4(int a, int b, int c, int d)
{ return max(max(a, b), max(c, d)); }

int main()
{
    int n, i; DNA s[MAXN];
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) switch (getchar()) {
        case 'A': s[i] = DNA_A; break;
        case 'C': s[i] = DNA_C; break;
        case 'G': s[i] = DNA_G; break;
        case 'T': s[i] = DNA_T; break;
        default: break;
    }
    int cnt[DNA_NUM_TYPES];
    for (i = 0; i < n; ++i) ++cnt[s[i]];
    int maxsym = max4(cnt[DNA_A], cnt[DNA_C], cnt[DNA_G], cnt[DNA_T]), maxtypecount = 0;
    for (i = 0; i < DNA_NUM_TYPES; ++i) maxtypecount += maxsym == cnt[i];
    long long ans = 1;
    for (i = 0; i < n; ++i) ans = (ans * maxtypecount) % DIVIDOR;
    printf("%I64d\n", ans);
    return 0;
}