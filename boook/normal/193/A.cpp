/*input
5 4
####
#..#
#..#
#..#
####
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
#define MAX 1000
#define INF 0x3f3f3f3f

int n , m , X[] = {-1 , 0 , 0 , 1} , Y[] = {0 , -1 , 1 , 0};
string s[MAX] , p[MAX];
int IN(int a , int b){
    return 0 <= a && a < n && 0 <= b && b < m;
}
void DFS(int a , int b){
    if(p[a][b] != '#') return ;
    p[a][b] = '.';
    if(IN(a - 1 , b)) DFS(a - 1 , b);
    if(IN(a + 1 , b)) DFS(a + 1 , b);
    if(IN(a , b + 1)) DFS(a , b + 1);
    if(IN(a , b - 1)) DFS(a , b - 1);
}
int solve(){
    int cnt = 0;
    REP(i , 0 , n) REP(j , 0 , m)
        if(p[i][j] == '#') cnt ++ , DFS(i , j);
    return cnt >= 2;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];

    int ans = 2 , sum = 0;
    REP(i , 0 , n) REP(j , 0 , m) {
        if(s[i][j] != '#') continue;
        sum ++;
        REP(k , 0 , n) p[k] = s[k];
        p[i][j] = '.';
        if(ans > 1 && solve()) ans = min(ans , 1);
    }
    if(sum <= 2) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}