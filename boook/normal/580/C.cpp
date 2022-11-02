#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200000
#define INF 0x3f3f3f3f

int ans = 0;
int col[MAX];
int n , m;
vector<int> v[MAX];
void DFS(int now , int cnt , int fa){
    if(cnt < 0) return ;
    if(v[now].size() == 1 && v[now][0] == fa){
        if(col[now]) cnt --;
        if(cnt >= 0) ans ++;
    }
    else if(col[now] == 0){
        for(auto to : v[now]){
            if(to != fa) DFS(to , m , now);
        }
    }
    else {
        for(auto to : v[now]){
            if(to != fa) DFS(to , cnt - 1 , now);
        }
    }
}
int32_t main(){
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> col[i];
    REP(i , 1 , n){
        int q , w;
        cin >> q >> w;
        v[q].pb(w) , v[w].pb(q);
    }
    DFS(1 , m , -1);
    cout << ans << endl;
    return 0;
}