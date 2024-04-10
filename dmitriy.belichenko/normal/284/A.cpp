
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 1e5;
int MOD = 1e9 + 7;
ll sum(ll a , ll b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

ll mult( ll a , ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int p;
    cin >> p;
    MOD = p;
    int ans = 0;
    for(int i = 1; i < p; i++)
    {
        int x = poww(i , p - 1);
        bool flag = 1;
        for(int j = 1; j <= p - 2; j++)
        {
            if(poww(i,j) == 1) flag = 0;
        }
        if(x == 1 && flag) ans++;
    }
    cout << ans << "\n";
    return 0;
}