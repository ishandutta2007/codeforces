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

int n , m;
vector<int> v[MAX];
PII DFS(int now , int fa){
    PII ans = mp(0 , now);
    for(auto to : v[now]){
        if(to == fa) continue;
        PII tmp = DFS(to , now);
        if(tmp.A + 1 > ans.A) ans = mp(tmp.A + 1 , tmp.B);
    }
    return ans;
}
int32_t main(){
    cin >> n >> m;
    REP(i , 0 , m){
        int q , w;
        cin >> q >> w;
        v[q].pb(w);
        v[w].pb(q);
    }
    cout << DFS(DFS(1 , 0).B , 0).A << endl;
    return 0;
}