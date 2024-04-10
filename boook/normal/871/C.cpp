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
#define MAX 300900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int two[MAX];
int n , x[MAX][2] , sol[MAX];
vector<int> v[MAX];
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int q , int w){ x[Find(q)] = Find(w); }
    int operator[](int now){ return Find(x[now]); }
}ds;
int cmp1(int a , int b){
    if(x[a][0] != x[b][0]) return x[a][0] < x[b][0];
    return x[a][1] < x[b][1];   
}
int cmp2(int a , int b){
    if(x[a][1] != x[b][1]) return x[a][1] < x[b][1]; 
    return x[a][0] < x[b][0];
} 
int32_t main(){
    IOS , ds.init();
    two[0] = 1;
    REP(i , 1 , MAX) two[i] = two[i - 1] * 2 % mod;


    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i][0] >> x[i][1];
    REP(i , 1 , n + 1) sol[i] = i;
    sort(sol + 1 , sol + 1 + n , cmp1);
    REP(i , 2 , n + 1){
        int a = sol[i - 1] , b = sol[i];
        if(x[a][0] == x[b][0]) ds.Union(a , b);
    }
    sort(sol + 1 , sol + 1 + n , cmp2);
    REP(i , 2 , n + 1){
        int a = sol[i - 1] , b = sol[i];
        if(x[a][1] == x[b][1]) ds.Union(a , b);
    }
    int ans = 1;
    set<int> cc , dd;
    REP(i , 1 , n + 1) v[ds[i]].pb(i);
    REP(i , 1 , n + 1){
        if(v[i].size() == 0) continue;
        // for(auto to : v[i]) cout << to << " " ; cout << endl;
        cc.clear() , dd.clear();
        for(auto to : v[i]) cc.insert(x[to][0]) , dd.insert(x[to][1]);
        int val = cc.size() + dd.size();
    // DB4("val = " , val , v[i].size() , "");
        if(val <= v[i].size()) ans = ans * two[val] % mod;
        else ans = ans * (two[val] + mod - 1) % mod;
    }
    cout << ans << endl;
    return 0;
}