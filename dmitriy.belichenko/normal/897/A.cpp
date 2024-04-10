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
const int MOD = 1e9 + 7;
using namespace std;
map<int, double > bi;
long long sum(long long a, long long b)
{
    a += b;
    if (a >= MOD)
        return a - MOD;
    else return a;
}
long long mult(long long a, long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
int poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n , m;
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++)
    {
        int l , r ;
        char c1 , c2;
        cin >> l >> r >> c1 >> c2;
        for(int j = l; j <= r; j++)
        {
            if(s[j - 1] == c1) s[j - 1] = c2;
        }
    }
    cout << s  << "\n";
}