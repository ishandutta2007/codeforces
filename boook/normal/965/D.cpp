/*input
10 3
1 1 1 1 2 1 1 1 1
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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , x[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    priority_queue<PII , vector<PII> , greater<PII> > pq;
    pq.push(mp(m , INF));
    REP(i , 1 , n + 1) if(x[i]){
        int cnt = 0;
        while(pq.size() && x[i]){
            PII now = pq.top(); pq.pop();
            if(now.A < i) continue;
            int sml = min(now.B , x[i]);
            now.B -= sml , x[i] -= sml;
            cnt += sml;
            if(now.B > 0) pq.push(mp(now.A , now.B));
        }
        if(cnt > 0) pq.push(mp(i + m , cnt));
    }
    int ans = 0;
    while(pq.size()) ans += (pq.top().A >= n) ? pq.top().B : 0 , pq.pop();
    cout << ans << endl;
    return 0;
}