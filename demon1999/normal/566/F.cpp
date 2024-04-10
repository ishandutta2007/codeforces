#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) (int)a.size()
#define re  return
#define vv vector
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;
int bb, a, n, m, dp[1000001], sum;
vector<int> b[1000001], uk(1000001, 0);
int main(){
    //iostream::sync_with_stdio(0);
    scanf("%d", &n);
    forn (i, n) {
        scanf("%d", &a);
        dp[a]++;
        for (int j = a + a; j < 1000001; j += a)
            dp[j] = max(dp[j], dp[a]);
        if (dp[a] > bb)
            bb = dp[a];
    }
    printf("%d", bb);
    re 0;
}