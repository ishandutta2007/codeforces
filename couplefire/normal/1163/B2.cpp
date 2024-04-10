#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 1e5 + 10;

int n, color, ans, mx, f[N], cnt[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color);
        cnt[f[color]]--;
        f[color]++;
        cnt[f[color]]++;
        mx = max(mx, f[color]);
        bool ok = false;
        if (cnt[1] == i) // every color has occurence of 1
            ok = true;
        else if (cnt[i] == 1) // only one color has the maximum occurence and the occurence is i
            ok = true;
        else if (cnt[1] == 1 && cnt[mx] * mx == i - 1) // one color has occurence of 1 and other colors have the same occurence
            ok = true;
        else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) // one color has the occurence 1 more than any other color
            ok = true;
        if (ok)
            ans = i;
    }
    printf("%d", ans);
	return 0;
}