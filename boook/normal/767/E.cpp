/*input
5 42
117 71 150 243 200
5 4 3 2 1
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
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m;
int x[MAX] , w[MAX];// , have[MAX];
int ans[MAX][2];

int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) cin >> w[i];
    
    int res = 0/* , id = 0*/;
    // priority_queue<PIII , vector<PIII> , greater<PIII> pq[210];
    priority_queue<PII , vector<PII> , greater<PII>> pq;
    REP(i , 1 , n + 1){

        ans[i][0] = x[i] / 100 , x[i] %= 100;

        if(x[i]) pq.push(mp((100 - x[i]) * w[i] , i));
        ans[i][1] = x[i];
        if(m >= x[i]){
            m -= x[i];
        }
        else {
            m = m + 100 - x[i];
            PII tmp = pq.top(); pq.pop();
            res += tmp.A;
            ans[tmp.B][0] ++;
            ans[tmp.B][1] = 0;
        }
        // DB4("res = " , res , "m = " , m);
    }
    // DBGG("m = " , m);
    cout << res << endl;
    REP(i , 1 , n + 1) cout << ans[i][0] << " " << ans[i][1] << endl;
    return 0;
}