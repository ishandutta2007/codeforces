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
#define MAX 400000
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX] , val[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i , val[i] = 0; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    int operator[](int now){ return Find(now); }
} ds;
int n , m , k;
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
    IOS;
    ds.init();
    cin >> n >> m >> k;
    REP(i , 1 , m + 1){
        int a , b;
        cin >> a >> b;
        ds.x[ds[a]] = ds[b];
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i , 1 , n + 1){
        if(ds[i] == i){
            int v = DFS(DFS(i , -1).B , -1).A;
            ds.val[ds[i]] = v;
        }
    }
    REP(i , 1 , k + 1){
        int a , b , c;
        cin >> a;
        if(a == 1) cin >> b , cout << ds.val[ds[b]] << endl;
        else{
            cin >> b >> c;
            b = ds[b] , c = ds[c];
            if(b != c){
                ds.x[b] = c;
                int q = ds.val[c] , w = ds.val[b];
                ds.val[c] = max(max(q , w) , (q + 1) / 2 + 1 + (w + 1) / 2);
            }
        }
    }
    return 0;
}