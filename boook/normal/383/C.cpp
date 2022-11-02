/*input
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
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
#define MAX 200900
#define INF 0x3f3f3f3f

void update(int now[MAX] , int from , int val){
    for(int i = from ; i < MAX ; i += i & -i)
        now[i] += val;
}
int query(int now[MAX] , int from){
    int cnt = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        cnt += now[i];
    return cnt;
}
int bit0[MAX] , bit1[MAX];
int n , m , x[MAX] , in[MAX] , out[MAX] , dep[MAX] , po = 0;
vector<int> v[MAX];
void DFS(int now , int fa , int deep){
     in[now] = ++po;
    dep[now] = deep;
    for(auto to : v[now]) if(to != fa) DFS(to , now , deep + 1);
    out[now] = po;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 2 , n + 1) {
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    DFS(1 , 0 , 0);
    REP(i , 1 , m + 1){
        int ty , a , b;
        cin >> ty;
        if(ty == 1){
            cin >> a >> b;
            if(dep[a] % 2 == 0){
                update(bit0 ,  in[a]     ,  b);
                update(bit0 , out[a] + 1 , -b);
                update(bit1 ,  in[a]     , -b);
                update(bit1 , out[a] + 1 ,  b);
            }
            if(dep[a] % 2 == 1){
                update(bit1 ,  in[a]     ,  b);
                update(bit1 , out[a] + 1 , -b);
                update(bit0 ,  in[a]     , -b);
                update(bit0 , out[a] + 1 ,  b);
            }
        }
        if(ty == 2){
            cin >> a;
            if(dep[a] % 2 == 0) cout << x[a] + query(bit0 ,  in[a]) << endl;
            if(dep[a] % 2 == 1) cout << x[a] + query(bit1 ,  in[a]) << endl;
        }
    }
    return 0;
}