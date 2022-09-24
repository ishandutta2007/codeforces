#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int sum(int a , int b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
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
set<char> gl = { 'a', 'e', 'i', 'o' , 'u' };
set<char> ch = { '1', '3', '5', '7' ,'9' };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int ans = 0 ;
    for(int i = 0; i < s.size(); i++)
    {
        if(gl.count(s[i]) || ch.count(s[i])) ans++;
    }
    cout << ans << "\n";
    return 0;
}