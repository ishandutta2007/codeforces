#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, c, C;
vector <int> k(10);
int dp[3000005];

int Hash(vector <int> v, int r)
{
    int ans = 0;

    for(int i = 0; i < 10; i++)
        ans = ans * (k[i] + 1) + v[i];

    ans = ans * m + r;

    return ans;
}

int add(int x, int y)
{
    x += y;

    while(x >= m)
        x -= m;

    while(x < 0)
        x += m;

    return x;
}

int sub(int x, int y)
{
    return add(x, m - y);
}

int mul(int x, int y)
{
    return x * y % m;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int f(vector <int> v, int r)
{
    if(C == 0)
        return (r == 0);

    int h = Hash(v, r);

//    for(auto x:v)
//        cout << x << ' ';
//
//    cout << "- " << r << endl;

    int x = dp[h];

    if(x > 0)
        return x - 1;

    int ans = 0;
    int b = binpow(10, C - 1);

    for(int i = 0; i < 10; i++)
    {
        if(v[i] > 0 && (i > 0 || C < c))
        {
            v[i]--;
            C--;
            int x = mul(i, b);
            r = sub(r, x);

            ans += f(v, r);

            r = add(r, x);
            C++;
            v[i]++;
        }
    }

    dp[h] = ans + 1;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int N = n;

    while(N > 0)
    {
        k[N % 10]++;
        N /= 10;
        c++;
    }

    C = c;

    cout << f(k, 0);
}