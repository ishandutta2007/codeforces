#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <iostream>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define po_b(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
typedef long long ll;
typedef long double ld;
using namespace std;
ll m, n, k, ans = 0;
char a[1000][1000];
bool ok;
vector <ll> dp(1000, 0);
int main()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        forn(j, m)cin >> a[i][j];
    }
    for(int i = 0; i < m; i++)
    {
        ok =true;
        for(int j = 0; j < n - 1; j++)
        {
            if(a[j][i] > a[j + 1][i] && dp[j] == 0)
            {
                ok =false; break;
            }
        }
        if(!ok)ans ++;
        if(ok)
        {
            for(int j = 0; j < n - 1; j++)
            {
                if(a[j][i] < a[j + 1][i])dp[j] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}