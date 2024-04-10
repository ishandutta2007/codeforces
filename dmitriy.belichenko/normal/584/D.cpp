
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
const int N = 2e5 + 5;
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
bool isprime(int n)
{
    for(int i = 2; i * i <= n; i++ )
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
bool used[N];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int closest  = n;
    while(true)
    {
        if(isprime(closest)) break;
        closest--;
    }
    if(closest == n)
    {
        cout << 1 << "\n" << n << "\n";
        return 0;
    }
    vector<int> pr;
    int del = n - closest;
    if(del == 2)
    {
        cout << 2 << "\n" << n - 2 << " " << 2 << "\n";
        return 0;
    }
    for(int i = 2; i <= del; i++)
    {
        if(isprime(i)) pr.pb(i);
    }
    for(int i = 0; i < pr.size(); i++)
    {
        for(int j = 0; j < pr.size(); j++)
        {
            if(pr[i] + pr[j] == del)
            {
                cout << 3 << "\n" << closest << " " << pr[i] << " " << pr[j] << "\n";
                return 0;
            }
        }
    }
    return 0;
}