/*input
50 50 1 1
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

int a , b , c , d;
int n = 50 , m = 40 , ans[MAX][MAX];
int32_t main(){
    IOS;
    cin >> a >> b >> c >> d;
    a -- , b -- , c -- , d --;
    REP(i , 1 , n + 1) REP(j , 01 , 10 + 1) ans[i][j] = 1;
    REP(i , 1 , n + 1) REP(j , 11 , 20 + 1) ans[i][j] = 2;
    REP(i , 1 , n + 1) REP(j , 21 , 30 + 1) ans[i][j] = 3;
    REP(i , 1 , n + 1) REP(j , 31 , 40 + 1) ans[i][j] = 4;

    int xx , pos;
    xx = 2 , pos = 1;
    while(b--){
        if(pos > n) pos = 1 , xx += 2;
        ans[pos][xx] = 2 , pos += 2;
    }
    xx = 12 , pos = 1;
    while(c--){
        if(pos > n) pos = 1 , xx += 2;
        ans[pos][xx] = 3 , pos += 2;
    }
    xx = 22 , pos = 1;
    while(d--){
        if(pos > n) pos = 1 , xx += 2;
        ans[pos][xx] = 4 , pos += 2;
    }
    xx = 32 , pos = 1;
    while(a--){
        if(pos > n) pos = 1 , xx += 2;
        ans[pos][xx] = 1 , pos += 2;
    }

    cout << n << " " << m << endl;
    REP(i , 1 , n + 1){
        REP(j , 1 , m + 1) cout << char(ans[i][j] - 1 + 'a');
        cout << endl;
    }
    return 0;
}