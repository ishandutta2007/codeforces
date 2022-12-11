#include <cstdio>
static const int MAXN = 104;

int n, ai, consec = 0; bool unlocked = false;
long long ans = 1;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai);
        if (ai == 0) ++consec;
        else {
            if (unlocked) ans *= (consec + 1);
            consec = 0; unlocked = true;
        }
    }
    printf("%I64d\n", unlocked ? ans : 0);
    return 0;
}