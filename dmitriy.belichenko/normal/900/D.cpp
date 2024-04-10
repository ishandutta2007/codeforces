#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
const int MOD = 1e9 + 7;
const int N = 1e5;
using namespace std;
map<int, int> cnt;
long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
vector<int> primes;
int sm(int a , int x)
{
    a += x;
    if(a >= MOD) a = a - MOD;
    return a;
}
int mn(int a , int x)
{
    a -= x;
    if(a < 0) a += MOD;
    return a;
}
int calc(int a)
{
    int sum = 0;
    for(int i = 0; i < primes.size();i++)
    {
        if(a % (primes[i] * primes[i]) == 0) return -1;
        while(a % primes[i] == 0)
        {
            a /= primes[i];
            sum++;
        }
    }
    return sum;
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
map<int , int> st;
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x , y;
    cin >> x >> y;
    if(y % x != 0)
    {
        cout << 0 << "\n";
        return  0;
    }
    y = y / x;
    
    {
        int p = y;
        for(int j = 2; j * j <= p ; j++)
        {
            if(p % j == 0)
            {
                primes.pb(j);
            }
            while( p % j == 0)
            {
                p/= j;
            }
        }
        if(p != 1) primes.pb(p);
        
    }
    int ans = 0;
    int sum1 = calc(y);
   // cout << calc(y) << "\n";
    for(int i = 1; i * i <= y; i++)
    {
        if(y % i == 0)
        {
            int sum = 0;
            sum =  calc(y / i);
            if(sum != -1)
            if( sum % 2 == 0)
            {
                ans = sm(ans , (int)poww(2 , i - 1));
            }
            else
            {
                ans = mn(ans , (int)poww(2 , i - 1));
                
            }
          //  cout << ans << " " << i << "\n";
            if(i * i == y) continue;
            sum =  calc(i);
             if(sum != -1)
            if( sum % 2 == 0)
            {
                ans = sm(ans , (int)poww(2 ,y /  i - 1) );
            }
            else
            {
                ans = mn(ans , (int)poww(2 ,y / i - 1));
                
            }
           //  cout << ans << " " << i << "\n";
        }
    }
    cout << ans <<"\n";
    return 0;
    
}