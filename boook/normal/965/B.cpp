/*input
19 6
##..............###
#......#####.....##
.....#########.....
....###########....
...#############...
..###############..
.#################.
.#################.
.#################.
.#################.
#####....##....####
####............###
####............###
#####...####...####
.#####..####..#####
...###........###..
....###########....
.........##........
#.................#
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
#define MAX 580
#define INF 0x3f3f3f3f

int n , len;
string s[MAX];
int OK(int i , int j){
    if(0 <= i && i < n && 0 <= j && j < n){
        return s[i][j] == '.';
    }
    else return 0;
}
int T(int now){
    if(now < len) return 0;
    else return now - len + 1;
}
int32_t main(){
    IOS;
    cin >> n >> len;
    REP(i , 0 , n) cin >> s[i];
    int big = 0;
    PII ans = mp(0 , 0) , now;
    // REP(i , 0 , n) cout << s[i] << endl;

    REP(i , 0 , n) REP(j , 0 , n) if(s[i][j] == '.') {
        // if(i != 0 || j != 7) continue;
        int cnt = 0 , l = 0 , r = 0 , u = 0 , d = 0;
        now = mp(i , j);
        while(OK(now.A - 1 , now.B)) l ++ , now.A --;
        now = mp(i , j);
        while(OK(now.A + 1 , now.B)) r ++ , now.A ++;

        // DBGG(now.A , now.B);
        now = mp(i , j);
        while(OK(now.A , now.B - 1)) u ++ , now.B --;
        now = mp(i , j);
        while(OK(now.A , now.B + 1)) d ++ , now.B ++;
        // DB4(l , r , u , d);
        if(len == 1) cnt = l + r + u + d + 1;
        else {
            cnt = T(l + r + 1) - T(l) - T(r) + T(u + d + 1) - T(d) - T(u);
        }
        // cout << cnt << endl;
        if(cnt > big) big = cnt , ans = mp(i , j);
        // return 0;
    }
    // cout << big << endl;
    cout << ans.A + 1 << " " << ans.B + 1 << endl;
    return 0;
}