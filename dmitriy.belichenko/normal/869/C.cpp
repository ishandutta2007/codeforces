#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e5;
const int INF = 1e9;
ll MOD = 998244353;

vector<vector<ll>> triangle;
vector<ll> fact(5006);

void generatePascal(int n)
{
    triangle.resize(n);
    triangle[0].push_back(1);
    for (int i = 1; i < n; ++i)
    {
        triangle[i].push_back(1);
        for (int j = 0; j < triangle[i - 1].size() - 1; ++j)
        {
            triangle[i].push_back((triangle[i - 1][j] % MOD + triangle[i - 1][j + 1] % MOD ) % MOD);
        }
        triangle[i].push_back(1);
    }
}

ll clc(ll a , ll b)
{
    ll sum = 0;
    for(int i = 0; i <= min(a , b); i++)
    {
        sum +=(( triangle[b][i] % MOD * triangle[a][i] % MOD) % MOD * fact[i] % MOD) % MOD;
    }
    return sum % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a , b , c;
    cin >> a >> b >> c;
    ll p = max(a , b);
    generatePascal(5005);
    fact[0] = 1;
    for(int i = 1; i <= 5005; i++)
    {
        fact[i] = (fact[i-1] % MOD * i % MOD) % MOD;
        
    }
    ll ans = 1LL * (((clc(a , b) % MOD) * clc(b , c) % MOD) % MOD * clc(a , c) % MOD) % MOD;
    cout << ans  % MOD << "\n";
    return 0;
}