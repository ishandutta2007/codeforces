
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
map<char,int> cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m;j++) cin >> b[j];
    int mn = 1e6;
    int mm = 1e6;
    for(int i= 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(a[i] == b[j]) mn = min(mn , a[i]);
        }
    if(mn != 1e6)
    {
        cout << mn ;
        return 0;
    }
    for(int i = 0; i < n; i++) mn = min(a[i] , mn);
    for(int i = 0; i < m; i++) mm = min(b[i] , mm);
  
    cout << min(mn , mm) << max(mn , mm) << " ";
     return 0;
}