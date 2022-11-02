/*input
4
2 3 4 5
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

int n , x[MAX];

int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    priority_queue<int , vector<int> , greater<int> > pq;
    REP(i , 1 , n + 1) pq.push(x[i]);
    int ans = 0;
    if(n % 2 == 0){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + b) , ans += a + b;
    }
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = pq.top(); pq.pop();
        pq.push(a + b + c) , ans += a + b + c;
    }
    cout << ans << endl;
    return 0;
}