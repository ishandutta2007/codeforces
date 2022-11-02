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
#define int long long
#define MAX 10
#define INF 0x3f3f3f3f

int n , a[MAX][MAX] , b[MAX][MAX] , q , w;
int use[MAX][MAX] , ans[10] , v[10];
int C(int x , int y){
    if(x == y) return 2;
    if(x == 1 && y == 3) return 0;
    if(x == 3 && y == 2) return 0;
    if(x == 2 && y == 1) return 0;
    return 1;
}
PII NXT(int x , int y){ return mp(a[x][y] , b[x][y]); }
int32_t main(){
    cin >> n >> q >> w;
    REP(i , 1 , 3 + 1) REP(j , 1 , 3 + 1) cin >> a[i][j];
    REP(i , 1 , 3 + 1) REP(j , 1 , 3 + 1) cin >> b[i][j];
    int step = 0;
    REP(times , 1 , INF){
        if(n == 0) break;
        if(use[q][w] == 0){
            use[q][w] = 1;

            n --;
            ans[C(q , w)] ++;
            PII tmp = NXT(q , w);
            q = tmp.A , w = tmp.B;
        }
        else if(use[q][w] == 1){
            use[q][w] = 2;
            v[C(q , w)] ++;
            step ++;

            n --;
            ans[C(q , w)] ++;
            PII tmp = NXT(q , w);
            q = tmp.A , w = tmp.B;
        }
        else if(use[q][w] == 2) break;
    }
    if(n > 100){
        int xx = n / step;
        n -= xx * step;
        ans[0] += xx * v[0];
        ans[1] += xx * v[1];
    }
    REP(i , 0 , n){
        ans[C(q , w)] ++;
        PII tmp = NXT(q , w);
        q = tmp.A , w = tmp.B;
    }
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}