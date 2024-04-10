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
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m;
long long ans;
int u[MAX][MAX] , d[MAX][MAX] , l[MAX][MAX] , r[MAX][MAX];
string s[MAX] , ss[MAX];
void solveinit(){
    REP(i , 0 , n) l[i][0] = (s[i][0] == '.') ? 1 : 0;
    REP(i , 0 , m) u[0][i] = (s[0][i] == '.') ? 1 : 0;
    REP(i , 0 , n) r[i][m - 1] = (s[i][m - 1] == '.') ? 1 : 0;
    REP(i , 0 , m) d[n - 1][i] = (s[n - 1][i] == '.') ? 1 : 0;

    REP(i , 0 , n) REP(j , 1 , m) l[i][j] = l[i][j - 1] * (s[i][j] == '.');
    REP(i , 1 , n) REP(j , 0 , m) u[i][j] = u[i - 1][j] * (s[i][j] == '.');
    REP(i , 0 , n) RREP(j , m - 2 , 0) r[i][j] = r[i][j + 1] * (s[i][j] == '.');
    RREP(i , n - 2 , 0) REP(j , 0 , m) d[i][j] = d[i + 1][j] * (s[i][j] == '.');
}
void solve(){
    solveinit();

    // REP(i , 0 , n){
    //     REP(j , 0 , m) cout << s[i][j] << " ";
    //     cout << endl;

    // } cout << "----" << endl;
    // REP(i , 0 , n){
    //     REP(j , 0 , m) cout << u[i][j] << " " ;
    //     cout << endl;
    // } cout << "&&&&&&&" << endl;

    REP(i , 1 , m - 1) if(d[0][i]) ans ++;
    REP(i , 1 , n - 1) REP(j , 1 , m - 1){
        if(r[i][j] && d[i][j]) ans ++;
        if(l[i][j] && u[i][j]) ans ++;
    }
    REP(i , 1 , n - 1){
        int up = 0 , dw = 0;
        REP(j , 1 , m - 1){
            if(s[i][j] == '#') up = 0 , dw = 0;
            else {
                if(u[i][j]){
                    ans += up + dw;
                    if(u[i][j - 1] && j - 1 > 0) ans --;
                }
                if(d[i][j]){
                    ans += up + dw;
                    if(d[i][j - 1] && j - 1 > 0) ans --;
                }
                if(u[i][j]) up ++;
                if(d[i][j]) dw ++;
            }
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , n) cin >> s[i];
    solve();
    REP(i , 0 , m) ss[i].resize(n);
    REP(i , 0 , n) REP(j , 0 , m) ss[j][n - 1 - i] = s[i][j];
    REP(i , 0 , m) s[i] = ss[i];
    swap(n , m);
    solve();
    cout << ans << endl;
    return 0;
}