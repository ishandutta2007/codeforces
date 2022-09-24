
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
string best[] = {
    "!x&x"
    , "!(x|y|z)"
    , "!x&!y&z"
    , "!x&!y"
    , "!x&!z&y"
    , "!x&!z"
    , "!(!y&!z|x|y&z)"
    , "!(x|y&z)"
    , "!x&y&z"
    , "!(!y&z|!z&y|x)"
    , "!x&z"
    , "!(!z&y|x)"
    , "!x&y"
    , "!(!y&z|x)"
    , "!x&(y|z)"
    , "!x"
    , "!y&!z&x"
    , "!y&!z"
    , "!(!x&!z|x&z|y)"
    , "!(x&z|y)"
    , "!(!x&!y|x&y|z)"
    , "!(x&y|z)"
    , "!(!x&!y|x&y|z)|!x&!y&z"
    , "!((x|y)&z|x&y)"
    , "!x&y&z|!y&!z&x"
    , "!x&y&z|!y&!z"
    , "!x&z|!y&!z&x"
    , "!x&z|!y&!z"
    , "!x&y|!y&!z&x"
    , "!x&y|!y&!z"
    , "!x&(y|z)|!y&!z&x"
    , "!x|!y&!z"
    , "!y&x&z"
    , "!(!x&z|!z&x|y)"
    , "!y&z"
    , "!(!z&x|y)"
    , "!x&!z&y|!y&x&z"
    , "!x&!z|!y&x&z"
    , "!x&!z&y|!y&z"
    , "!x&!z|!y&z"
    , "!x&y&z|!y&x&z"
    , "!(!x&z|!z&x|y)|!x&y&z"
    , "!(x&y)&z"
    , "!(!z&x|y)|!x&z"
    , "!x&y|!y&x&z"
    , "!(!y&z|x)|!y&x&z"
    , "!x&y|!y&z"
    , "!x|!y&z"
    , "!y&x"
    , "!(!x&z|y)"
    , "!y&(x|z)"
    , "!y"
    , "!x&!z&y|!y&x"
    , "!x&!z|!y&x"
    , "!x&!z&y|!y&(x|z)"
    , "!x&!z|!y"
    , "!x&y&z|!y&x"
    , "!(!x&z|y)|!x&y&z"
    , "!x&z|!y&x"
    , "!x&z|!y"
    , "!x&y|!y&x"
    , "!(!x&!y&z|x&y)"
    , "!x&(y|z)|!y&x"
    , "!x|!y"
    , "!z&x&y"
    , "!(!x&y|!y&x|z)"
    , "!x&!y&z|!z&x&y"
    , "!x&!y|!z&x&y"
    , "!z&y"
    , "!(!y&x|z)"
    , "!x&!y&z|!z&y"
    , "!x&!y|!z&y"
    , "!x&y&z|!z&x&y"
    , "!(!x&y|!y&x|z)|!x&y&z"
    , "!x&z|!z&x&y"
    , "!(!z&y|x)|!z&x&y"
    , "!(x&z)&y"
    , "!(!y&x|z)|!x&y"
    , "!x&z|!z&y"
    , "!x|!z&y"
    , "!z&x"
    , "!(!x&y|z)"
    , "!x&!y&z|!z&x"
    , "!x&!y|!z&x"
    , "!z&(x|y)"
    , "!z"
    , "!x&!y&z|!z&(x|y)"
    , "!x&!y|!z"
    , "!x&y&z|!z&x"
    , "!(!x&y|z)|!x&y&z"
    , "!x&z|!z&x"
    , "!(!x&!z&y|x&z)"
    , "!x&y|!z&x"
    , "!x&y|!z"
    , "!x&(y|z)|!z&x"
    , "!x|!z"
    , "!y&x&z|!z&x&y"
    , "!(!x&y|!y&x|z)|!y&x&z"
    , "!y&z|!z&x&y"
    , "!(!z&x|y)|!z&x&y"
    , "!y&x&z|!z&y"
    , "!(!y&x|z)|!y&x&z"
    , "!y&z|!z&y"
    , "!(!y&!z&x|y&z)"
    , "!x&y&z|!y&x&z|!z&x&y"
    , "!(!x&y|!y&x|z)|!x&y&z|!y&x&z"
    , "!(x&y)&z|!z&x&y"
    , "!(!z&x|y)|!x&z|!z&x&y"
    , "!(x&z)&y|!y&x&z"
    , "!(!y&x|z)|!x&y|!y&x&z"
    , "!(x&y)&z|!z&y"
    , "!x|!y&z|!z&y"
    , "!(y&z)&x"
    , "!(!x&y|z)|!y&x"
    , "!y&z|!z&x"
    , "!y|!z&x"
    , "!y&x|!z&y"
    , "!y&x|!z"
    , "!y&(x|z)|!z&y"
    , "!y|!z"
    , "!(y&z)&x|!x&y&z"
    , "!(!x&y|z)|!x&y&z|!y&x"
    , "!(x&y)&z|!z&x"
    , "!x&z|!y|!z&x"
    , "!(x&z)&y|!y&x"
    , "!x&y|!y&x|!z"
    , "!x&y|!y&z|!z&x"
    , "!(x&y&z)"
    , "x&y&z"
    , "!(x|y|z)|x&y&z"
    , "!x&!y&z|x&y&z"
    , "!x&!y|x&y&z"
    , "!x&!z&y|x&y&z"
    , "!x&!z|x&y&z"
    , "!(!y&!z|x|y&z)|x&y&z"
    , "!(x|y&z)|x&y&z"
    , "y&z"
    , "!(x|y|z)|y&z"
    , "!x&z|y&z"
    , "!x&!y|y&z"
    , "!x&y|y&z"
    , "!x&!z|y&z"
    , "!x&(y|z)|y&z"
    , "!x|y&z"
    , "!y&!z&x|x&y&z"
    , "!y&!z|x&y&z"
    , "!(!x&!z|x&z|y)|x&y&z"
    , "!(x&z|y)|x&y&z"
    , "!(!x&!y|x&y|z)|x&y&z"
    , "!(x&y|z)|x&y&z"
    , "!(!x&!y|x&y|z)|!x&!y&z|x&y&z"
    , "!((x|y)&z|x&y)|x&y&z"
    , "!y&!z&x|y&z"
    , "!y&!z|y&z"
    , "!x&z|!y&!z&x|y&z"
    , "!(x&z|y)|y&z"
    , "!x&y|!y&!z&x|y&z"
    , "!(x&y|z)|y&z"
    , "!x&(y|z)|!y&!z&x|y&z"
    , "!x|!y&!z|y&z"
    , "x&z"
    , "!(x|y|z)|x&z"
    , "!y&z|x&z"
    , "!x&!y|x&z"
    , "!x&!z&y|x&z"
    , "!x&!z|x&z"
    , "!x&!z&y|!y&z|x&z"
    , "!(x|y&z)|x&z"
    , "(x|y)&z"
    , "!(x|y|z)|(x|y)&z"
    , "z"
    , "!x&!y|z"
    , "!x&y|x&z"
    , "!(!y&z|x)|x&z"
    , "!x&y|z"
    , "!x|z"
    , "!y&x|x&z"
    , "!y&!z|x&z"
    , "!y&(x|z)|x&z"
    , "!y|x&z"
    , "!x&!z&y|!y&x|x&z"
    , "!(x&y|z)|x&z"
    , "!x&!z&y|!y&(x|z)|x&z"
    , "!x&!z|!y|x&z"
    , "!y&x|y&z"
    , "!(!x&z|y)|y&z"
    , "!y&x|z"
    , "!y|z"
    , "!x&y|!y&x|x&z"
    , "!x&!z|!y&x|y&z"
    , "!x&y|!y&x|z"
    , "!x|!y|z"
    , "x&y"
    , "!(x|y|z)|x&y"
    , "!x&!y&z|x&y"
    , "!x&!y|x&y"
    , "!z&y|x&y"
    , "!x&!z|x&y"
    , "!x&!y&z|!z&y|x&y"
    , "!(x|y&z)|x&y"
    , "(x|z)&y"
    , "!(x|y|z)|(x|z)&y"
    , "!x&z|x&y"
    , "!(!z&y|x)|x&y"
    , "y"
    , "!x&!z|y"
    , "!x&z|y"
    , "!x|y"
    , "!z&x|x&y"
    , "!y&!z|x&y"
    , "!x&!y&z|!z&x|x&y"
    , "!(x&z|y)|x&y"
    , "!z&(x|y)|x&y"
    , "!z|x&y"
    , "!x&!y&z|!z&(x|y)|x&y"
    , "!x&!y|!z|x&y"
    , "!z&x|y&z"
    , "!(!x&y|z)|y&z"
    , "!x&z|!z&x|x&y"
    , "!x&!y|!z&x|y&z"
    , "!z&x|y"
    , "!z|y"
    , "!x&z|!z&x|y"
    , "!x|!z|y"
    , "(y|z)&x"
    , "!(x|y|z)|(y|z)&x"
    , "!y&z|x&y"
    , "!(!z&x|y)|x&y"
    , "!z&y|x&z"
    , "!(!y&x|z)|x&z"
    , "!y&z|!z&y|x&y"
    , "!x&!y|!z&y|x&z"
    , "(x|y)&z|x&y"
    , "!(x|y|z)|(x|y)&z|x&y"
    , "x&y|z"
    , "!x&!y|x&y|z"
    , "x&z|y"
    , "!x&!z|x&z|y"
    , "y|z"
    , "!x|y|z"
    , "x"
    , "!y&!z|x"
    , "!y&z|x"
    , "!y|x"
    , "!z&y|x"
    , "!z|x"
    , "!y&z|!z&y|x"
    , "!y|!z|x"
    , "x|y&z"
    , "!y&!z|x|y&z"
    , "x|z"
    , "!y|x|z"
    , "x|y"
    , "!z|x|y"
    , "x|y|z"
    , "!x|x"
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
       bitset<8> t;
       cin >> s;
       for(int i = 0; i < 8; i++) t[i] = s[i] - '0';
       cout << best[t.to_ulong()] << "\n";
    }
    return 0;
}