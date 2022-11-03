/*input
8
-67761 603277
640586 -396671
46147 -122580
569609 -2112
400 914208
131792 309779
-850150 -486293
5272 721899
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX][2] , sol[MAX] , ans[MAX];
inline int DIS(int a , int b){ return a * a + b * b; }
int cmp(int a , int b){
    return DIS(x[a][0] , x[a][1]) > DIS(x[b][0] , x[b][1]);
}
int32_t main(){
    srand(time(NULL));
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp);

    int xx = 0 , yy = 0;
    REP(idx , 1 , n + 1){ int i = idx;
        if(DIS(xx + x[i][0] , yy + x[i][1]) < DIS(xx - x[i][0] , yy - x[i][1]))
             xx += x[i][0] , yy += x[i][1] , ans[i] = 1;
        else xx -= x[i][0] , yy -= x[i][1] , ans[i] = -1;
    }
    while(DIS(xx , yy) > 2.25 * 1e12){
        int i = rand() % n + 1;
        int tox = xx - x[i][0] * ans[i] * 2;
        int toy = yy - x[i][1] * ans[i] * 2;
        if(DIS(tox , toy) < DIS(xx , yy)){
            xx = tox , yy = toy , ans[i] = -ans[i];
        }
    }
    REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}