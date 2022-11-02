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
#define int long long
#define MAX 200000
#define INF 0x3f3f3f3f

int n , m , o[MAX];
int col[MAX] , ok = 1;
vector<int> v[MAX];
int DFS(int now , int tobe){
    if(col[now] != 0 && col[now] != tobe) return ok = 0;
    else col[now] = tobe;
    for(auto to : v[now]){
        if(col[to] == 0) DFS(to , 3 - tobe);
        else if(col[to] == tobe) return ok = 0;
    }
    return tobe;
}
int use[MAX];
PII DFS2(int now){
    if(use[now]) return mp(0 , 0);
    use[now] = 1;
    PII ans = mp(0 , 0);
    if(col[now] == 1) ans.A++;
    if(col[now] == 2) ans.B++;
    for(auto to : v[now]){
        if(use[to]) continue;
        PII tmp = DFS2(to);
        ans.A += tmp.A;
        ans.B += tmp.B;
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
    REP(i , 1 , n + 1) if(col[i] == 0) DFS(i , 1);
    if(ok == 0){
        cout << 0 << " " << 1 << endl;
        return 0;
    }
    else if(m == 0){
        int tmp = (n) * (n - 1) * (n - 2) / 6;
        cout << 3 << " " << tmp << endl;
    }
    else {
        int tmp = 0;
        REP(i , 1 , n + 1){
            if(use[i] == 0){
                PII res = DFS2(i);
                tmp += res.A * (res.A - 1) / 2;
                tmp += res.B * (res.B - 1) / 2;
            }
        }
        if(tmp != 0) cout << 1 << " " << tmp << endl;
        else{
            int res = (n - 2) * m;
            cout << 2 << " " << res << endl;
        }
    }
    return 0;
}