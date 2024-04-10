#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;
const int MOD = 1e9 + 7;

string s;
int n, pow10[100005], ans[100005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();

    pow10[0] = 1;

    for(int i = 1; i < 100005; i++)
        pow10[i] = mul(10, pow10[i - 1]);

    ans[1] = 0;
    int x = 1;

    for(int i = 2; i <= n; i++)
    {
        ans[i] = add(ans[i - 1], mul(x, pow10[i - 2]));
        x++;
    }

    int y = 0;

    for(int i = 0; i < n; i++)
    {
        y = add(y, mul(mul(s[i] - '0', pow10[n - 1 - i]), i * (i + 1) / 2));
        y = add(y, mul(ans[n - i], (s[i] - '0')));
    }

    cout << y;
}