/*input
6
1 2 3 2 1 4
6 7 1 2 3 2
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

int n , a[MAX] , b[MAX];
int sml[MAX][20] , big[MAX][20] , low[MAX];
void solveinit(){
    REP(i , 2 , n + 1) low[i] = low[i >> 1] + 1;
    REP(i , 1 , n + 1) big[i][0] = a[i];
    REP(i , 1 , n + 1) sml[i][0] = b[i];
    REP(j , 1 , 20) REP(i , 1 , n + 1){
        int to = i + (1 << (j - 1));
        if(to > n) continue;
        sml[i][j] = min(sml[i][j - 1] , sml[to][j - 1]);
        big[i][j] = max(big[i][j - 1] , big[to][j - 1]);
    }
}
int smlquery(int l , int r){
    int tmp = low[r - l + 1];
    return min(sml[l][tmp] , sml[r - (1 << tmp) + 1][tmp]);
}
int bigquery(int l , int r){
    int tmp = low[r - l + 1];
    return max(big[l][tmp] , big[r - (1 << tmp) + 1][tmp]);
}
void solve(){
    long long ans = 0;
    REP(i , 1 , n + 1){
        int l = i , r = i;
        RREP(j , 19 , 0){
            int to = l + (1 << j);
            if(to > n) continue;
            int ss = smlquery(i , to) , bb = bigquery(i , to);
            if(bb < ss) l = to;
        }
        if(a[i] != b[i]) l ++;
        RREP(j , 19 , 0){
            int to = r + (1 << j);
            if(to > n) continue;
            int ss = smlquery(i , to) , bb = bigquery(i , to);
            if(bb <= ss) r = to;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}
int32_t main(){
    IOS , cin >> n;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    solveinit();
    solve();
    return 0;
}