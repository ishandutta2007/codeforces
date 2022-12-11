#include <cstdio>
#include <cstring>
static const int MAXN = 100004;

int k;
char n[MAXN];
int ct[10] = { 0 };

int main()
{
    scanf("%d", &k);
    scanf("%s", n);
    int l = strlen(n);

    int sum = 0;
    for (int i = 0; i < l; ++i) {
        n[i] -= '0';
        sum += n[i];
        ++ct[9 - n[i]];
    }
    if (sum >= k) puts("0");
    else {
        int ans = 0;
        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < ct[i]; ++j) {
                ++ans;
                if ((sum += i) >= k) { printf("%d\n", ans); return 0; }
            }
        }
    }

    return 0;
}