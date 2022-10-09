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

int n, a, b;
vector<int> v;

const long long INF64 = (long long)(1e18);

set<int> used;

long long solve(int x)
{
    if(used.count(x))
        return INF64;
    used.insert(x);
    vector<long long> cost(n);
    for(int i = 0; i < n; i++)
    {
        if(v[i] % x == 0)
            cost[i] = 0;
        else if((v[i] + 1) % x == 0 || (v[i] - 1) % x == 0)
            cost[i] = b;
        else
            cost[i] = INF64;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(3, INF64));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
        {                                   
            if(dp[i][j] == INF64) continue;
            //cout << i << " " << j << " " << dp[i][j] << endl;
            if(j <= 0)
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + cost[i]);
            if(j <= 1)
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + a);
            if(j <= 2)
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][j] + (j == 2 ? cost[i] : a));
        }
    return *min_element(dp[n].begin(), dp[n].end());
}

long long solve_fact(int x)
{
    long long res = INF64;
    vector<int> factorization;
    for(int i = 2; i * 1ll * i <= x; i++)
    {
        if(x % i == 0)
        {
            factorization.push_back(i);
            while(x % i == 0)
                x /= i;
        }
    }
    if(x != 1)
        factorization.push_back(x);
    for(auto f : factorization)
    {
        //cerr << f << " " << solve(f) << endl;
        res = min(res, solve(f));
    }
    return res;
}
 
int main()
{               
    scanf("%d %d %d", &n, &a, &b);
    v.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);  
    long long ans = INF64;
    vector<int> t = {v[0] - 1, v[0], v[0] + 1, v.back() - 1, v.back(), v.back() + 1};
    for(auto x : t)
        ans = min(ans, solve_fact(x));
    cout << ans << endl;
}