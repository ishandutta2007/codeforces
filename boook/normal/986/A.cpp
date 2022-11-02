/*input
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7
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

int n , m , k , lim , dis[MAX] , x[MAX];
vector<int> v[MAX];
priority_queue<int> pq[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k >> lim;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i , 1 , k + 1){
        MEM(dis , INF);
        queue<int> qu;
        REP(j , 1 , n + 1) if(x[j] == i) dis[j] = 0 , qu.push(j);
        while(qu.size()){
            int now = qu.front(); qu.pop();
            for(auto to : v[now]){
                if(dis[to] > dis[now] + 1){
                    dis[to] = dis[now] + 1;
                    qu.push(to);
                }
            }
        }        
        REP(j , 1 , n + 1) if(x[j] != i) pq[j].push(dis[j]);
    }
    REP(i , 1 , n + 1){
        int all = 0;
        while(pq[i].size() != lim - 1) pq[i].pop();
        while(pq[i].size() != 0) all += pq[i].top() , pq[i].pop();
        cout << all << " ";
    }
    cout << endl;
    return 0;
}