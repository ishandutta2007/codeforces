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
#define MAX 40
#define INF 0x3f3f3f3f

int n , ans[MAX][2];
vector<int> v[MAX];
int X[] = {0 , 1 , 0 , -1};
int Y[] = {1 , 0 , -1 , 0};
void DFS(int now , int fa , int a , int b , int dir , int dis){
    ans[now][0] = a;
    ans[now][1] = b;
    dir = (dir + 3) % 4;
    for(auto to : v[now]){
        if(to == fa) continue;
        int aa = a + (1LL << dis) * X[dir];
        int bb = b + (1LL << dis) * Y[dir];
        DFS(to , now , aa , bb , dir , dis - 1);
        dir = (dir + 1) % 4;
    }
}
int32_t main(){
    cin >> n;
    REP(i , 1 , n){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i , 1 , n + 1){
        if(v[i].size() > 4) return cout << "NO" << endl , 0; 
    }
    cout << "YES" << endl; 
    if(n == 1){
        cout << "0 0" << endl;
    }
    else {
        ans[1][0] = ans[1][1] = 0;
        REP(i , 0 , v[1].size()){
            int to = v[1][i] , d = 35;
            DFS(to , 1 , (1LL << 35) * X[i] , (1LL << 35) * Y[i] , i , 34);
        }
        REP(i , 1 , n + 1) cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}