/*input
4 16
10 8
7 4
3 1
5 4
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
#define MAX 212345
#define INF 0x3f3f3f3f

int n , m , a[MAX] , b[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> b[i] >> a[i];
    int sum = 0 , have = 0;
    REP(i , 1 , n + 1) sum += a[i];
    REP(i , 1 , n + 1) have += b[i];
    if(sum > m) return cout << -1 << endl , 0;
    priority_queue<int> pq;
    REP(i , 1 , n + 1) pq.push(b[i] - a[i]);
    int ans = 0;
    while(have > m){
        int now = pq.top(); pq.pop();
        have -= now;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}