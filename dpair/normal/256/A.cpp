#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

template <typename T>
inline void fprint(T x)
{
    if(x < 0)
    {
        putchar(45);
        x = -x;
    }
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}

template <typename T>
inline void read(T &x)
{
    x = 0;
    int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48)
    {
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48)
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}

int n;
int a[4010];
int dp[4010][4010];
int ans;
int main()
{
	read(n);
	for (register int i = 1;i <= n;i ++) read(a[i]);
	for (register int i = 1;i <= n;i ++)
	{
		int pre = 0;
		for (register int j = 0;j < i;j ++)
		{
			dp[i][j] = dp[j][pre] + 1;
			if(a[i] == a[j]) pre = j;
			ans = max(ans, dp[i][j]);
		}
	}
	fprint(ans);
}