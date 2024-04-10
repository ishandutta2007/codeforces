/*input
20 10
commonprefixhello
commonprefixhow
commonprefixdo
commonprefixyou
commonprefixdo
commonprefixaaabd
commonprefixaaab
commonprefixabddef
commonprefixbaaaae
commonprefixbaae
commonprefixbaaade
commonprefixaedbed
commonprefixaeeee
commonprefixbbbbb
commonprefixbebe
commonprefixbebeb
commonprefixbye
commonprefixsee
commonprefixyou
commonprefixlater
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 4020
#define INF 0x3f3f3f3f
#define AC  10430579
#define mod 1000000007LL

int n , m , lcp[MAX] , dp[MAX][MAX] , idx[MAX][MAX] , idxpo = 0;
string s[MAX];

int DP(int take , int l , int r){
    // if(idx[l][r] == 0) DBGG(l , r);
    if(idx[l][r] == 0) idx[l][r] = ++idxpo;
    assert(idxpo < n + n + 10);

    if(dp[take][idx[l][r]] != -1) return dp[take][idx[l][r]];
    if(l == r) return dp[take][idx[l][r]] = 0;
    else {
        int sml = INF , tmp , val = 0;
        REP(i , l + 1 , r + 1) if(lcp[i] < sml) sml = lcp[i] , tmp = i;
        REP(i , 0 , take + 1){
            int v1 = i , v2 = take - i;
            int base = v1 * v2 * sml;
            if(v1 <= tmp - l && v2 <= r - tmp + 1){
                val = max(val , DP(v1 , l , tmp - 1) + DP(v2 , tmp , r) + base);
            }
        }
        return dp[take][idx[l][r]] = val;
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> s[i];
    sort(s + 1 , s + 1 + n);
    MEM(dp , -1);
    REP(i , 2 , n + 1){
        lcp[i] = 0;
        while(lcp[i] < s[i - 1].size() && lcp[i] < s[i].size() && s[i - 1][lcp[i]] == s[i][lcp[i]]) lcp[i]++;
    }
    cout << DP(m , 1 , n)<< endl;
    return 0;
}