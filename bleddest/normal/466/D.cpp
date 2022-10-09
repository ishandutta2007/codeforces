#define _CRT_SECURE_NO_WARNINGS
 
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>
 
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
 
int main()
{
    int n;
    cin >> n;
    int h;
    cin >> h;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<modInt> > dp(n + 1, vector<modInt>(h + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= h; j++)
        {
            if(a[i] + j == h) //      
                dp[i + 1][j] = dp[i + 1][j] + dp[i][j];
            if(a[i] + (j + 1) == h) //   
                dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i][j];
            if(j > 0 && a[i] + (j - 1) == h) //  ,   
                dp[i + 1][j - 1] = dp[i + 1][j - 1] + dp[i][j] * j;
            if(a[i] + j == h) //    
                dp[i + 1][j] = dp[i + 1][j] + dp[i][j] * j;      
        }
    cout << dp[n][0] + dp[n][1] << endl;
}