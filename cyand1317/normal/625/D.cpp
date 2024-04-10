// Maybe it's time to re-evaluate
#include <cstdio>
static const int MAXN = 100005;

int n;
int s[MAXN], ans[MAXN];

bool check(int p, int q, int hd, int tl)
{
    if (hd < 0 || hd > 19) return false;
    if (p == q) {
        if (hd % 2 == 0) { ans[p] = hd / 2; return true; }
        else return false;
    }
    if (p == q + 1) {
        int t = hd * 10 + tl;
        if (t % 11 == 0 && t >= 0 && t <= 198) {
            ans[q] = t / 22; ans[p] = t / 11 - t / 22; return true;
        } else return false;
    }
    if (p == q + 2) {
        int t = hd * 100 + s[q + 1] * 10 + tl;
        for (int i = 0; i <= 18; ++i) if ((t - i * 101) % 20 == 0) {
            int b = (t - i * 101) / 20;
            if (b >= 0 && b <= 9) {
                ans[q] = i / 2; ans[p] = i - i / 2; ans[q + 1] = b; return true;
            }
        }
        return false;
    }
    if (hd == tl || hd == tl + 1) { // No carries
        ans[q] = tl / 2; ans[p] = tl - tl / 2;
        if (ans[p] >= 10 || ans[q] >= 10 || ans[p] < 0 || ans[q] < 0) return false;
        return check(p - 1, q + 1, (hd - tl) * 10 + s[p - 1], s[q + 1]);
    } else if (hd == tl + 10 || hd == tl + 11) {    // Carries
        ans[q] = tl / 2 + 5; ans[p] = tl - tl / 2 + 5;
        if (ans[p] >= 10 || ans[q] >= 10 || ans[p] < 0 || ans[q] < 0) return false;
        return check(p - 1, q + 1, (hd - tl - 10) * 10 + s[p - 1], s[q + 1] - 1);
    }
    return false;
}

int main()
{
    n = 0; while ((s[n] = getchar() - '0') >= 0 && s[n] <= 9) ++n;
    for (int i = 0; i < n / 2; ++i) { int t = s[i]; s[i] = s[n - 1 - i]; s[n - 1 - i] = t; }
    if (check(n - 1, 0, s[n - 1], s[0]) && ans[n - 1] != 0)
        for (int i = n - 1; i >= 0; --i) putchar('0' + ans[i]);
    else if (check(n - 2, 0, s[n - 1] * 10 + s[n - 2], s[0]) && ans[n - 2] != 0)
        for (int i = n - 2; i >= 0; --i) putchar('0' + ans[i]);
    else puts("0");

    return 0;
}