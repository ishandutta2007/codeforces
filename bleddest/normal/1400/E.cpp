#define _CRT_SECURE_NO_WARNINGS
 
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>
#include<unordered_map>
 
const int MOD = int(1e9) + 7;
 
using namespace std;
 
struct modInt
{
    int x;
    modInt() : x(0) {};
    modInt(int x) : x(x) {};
};
 
modInt operator +(const modInt& x, const modInt& y)
{
    int z = x.x + y.x;
    while (z >= MOD)
        z -= MOD;
    while (z < 0)
        z += MOD;
    return modInt(z);
}
 
modInt operator -(const modInt& x, const modInt& y)
{
    int z = x.x - y.x;
    while (z >= MOD)
        z -= MOD;
    while (z < 0)
        z += MOD;
    return modInt(z);
}
 
modInt operator *(const modInt& x, const modInt& y)
{
    return modInt((x.x * 1ll * y.x) % MOD);
}
 
modInt operator ^(const modInt& x, const modInt& y)
{
    modInt res(1);
    modInt xx = x;
    int yx = y.x;
    while (yx > 0)
    {
        if (yx % 2 == 1)
            res = res * xx;
        xx = xx * xx;
        yx /= 2;
    }
    return res;
}
 
modInt operator /(const modInt& x, const modInt& y)
{
    return x * (y ^ (MOD - 2));
}
 
bool operator <(const modInt& x, const modInt& y)
{
    return x.x < y.x;
}
 
ostream& operator <<(ostream& out, const modInt& x)
{
    return out << x.x;
}

void upd(vector<int>& m, int x, int y)
{
    m[x] = min(m[x], y);
}
 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, int(1e9)));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            long long k = dp[i][j];
            if(k > n)
                continue;
            if(j > a[i])
                upd(dp[i + 1], a[i], k);
            else
            {
                upd(dp[i + 1], j, k + (j < a[i] ? 1 : 0));
                if(a[i] <= n)
                {
                    upd(dp[i + 1], a[i], k + (a[i] - j));
                }
            }
        }                                       
    }
    int ans = (int)(1e9);
    for(auto p : dp[n])
        ans = min(ans, p);
    cout << ans << endl;
}