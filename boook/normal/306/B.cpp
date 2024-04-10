/*input
20 10
7 2
12 2
14 1
4 3
17 4
9 3
15 4
12 2
18 1
12 1
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
#define MAX 2000090
#define INF 0x3f3f3f3f

int n , m;
vector<int> ans;
vector<PII> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , m + 1){
        int id , len;
        cin >> id >> len;
        v[id].pb(mp(i , id + len - 1));
    }
    int now = 1;
    while(now <= n){
        if(v[now].size()){
            int nxt = 0 , id;
            for(auto to : v[now]) if(to.B > nxt){
                nxt = to.B , id = to.A;
            }
            for(auto to : v[now]) if(to.A != id){
                ans.pb(to.A);
            }
            REP(mid , now + 1 , nxt + 1) for(auto to : v[mid]){
                if(to.B > nxt) v[nxt + 1].pb(to);
                else ans.pb(to.A);
            }
            now = nxt + 1;
        }
        else now ++;
    }

    cout << ans.size() << endl;
    for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}