/*input
2
5 BA
11 CB
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
#define int long long
#define MAX 
#define INF 0x3f3f3f3f

int c[10];
int32_t main(){
    IOS;
    REP(i , 0 , 10) c[i] = INF;
    c[0] = 0;
    int n , in;
    string s;
    cin >> n;
    REP(i , 1 , n + 1){
        cin >> in >> s;
        int pat = 0;
        REP(j , 0 , s.size()) pat |= (1 << (s[j] - 'A'));
        c[pat] = min(c[pat] , in);
    }
    int ans = INF + INF;
    REP(i , 0 , 8) REP(j , 0 , 8) REP(k , 0 , 8){
        if((i | j | k) == 7) ans = min(ans , c[i] + c[j] + c[k]);
    }
    if(ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}