/*input
5 2
1 3 2 3 5
2 3
5 1
3 4
4 1
2
1 2
2 3
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

vector<int> v[MAX] , d[MAX] , p[MAX] , h[MAX];
int use[MAX] , siz[MAX] , dep[MAX] , x[MAX] , in[MAX] , out[MAX] , po;
void Getdep(int now , int fa , int deep){
    in[now] = po ++;
    dep[now] = deep;
    for(auto to : v[now]){
        if(to != fa) Getdep(to , now , deep + 1);
    }
    out[now] = po ++;
}
PII Center(int now , int fa , int all){
    PII res = mp(INF , now);
    siz[now] = 1;
    int big = 0;
    for(auto to : v[now]){
        if(use[to] || to == fa) continue;
        res = min(res , Center(to , now , all));
        siz[now] += siz[to];
        big = max(big , siz[to]);
    }
    big = max(big , all - siz[now]);
    res = min(res , mp(big , now));
    return res;
}
void Getdis(int now , int fa , int dis , int root){
    p[now].pb(root);
    d[now].pb(dis);
    if(dis == h[root].size()) h[root].pb(INF);
    for(auto to : v[now]){
        if(use[to] || to == fa) continue;
        Getdis(to , now , dis + 1 , root);
    }
}
int PA(int fa , int now){
    return (in[fa] <= in[now] && out[fa] >= out[now]);
}
void Getsml(int now , int fa , int root){
    if(PA(root , now)){
        int dis = dep[now] - dep[root];
        h[root][dis] = min(h[root][dis] , x[now]);
    }
    for(auto to : v[now]){
        if(use[to] || to == fa) continue;
        Getsml(to , now , root);
    }
}
void solveinit(int now , int all){
    now = Center(now , 0 , all).B;
    use[now] = 1;
    for(auto to : v[now]){
        if(use[to] == 0) solveinit(to , siz[to]);
    }
    Getdis(now , 0 , 0 , now);
    Getsml(now , 0 , now);
    REP(i , 1 , h[now].size()) h[now][i] = min(h[now][i] , h[now][i - 1]);
    // cout << now << " : ";
    // for(auto to : h[now]) cout << to << " " ; cout << endl;
    use[now] = 0;
}
int n , m , root;
int query(int now , int len){
    int ans = x[now];
    REP(i , 0 , d[now].size()){
        int to = p[now][i];
        int tmp = len - d[now][i];
        if(tmp >= 0 && PA(now , to)){
            if(tmp < h[to].size())
                 ans = min(ans , h[to][tmp]);
            else ans = min(ans , h[to].back());
        }
    }
    return ans;
}
int32_t main(){
    IOS , cin >> n >> root;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 0){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    Getdep(root , 0 , 0);
    solveinit(root , n);
    int lastans = 0;
    cin >> m;
    REP(i , 1 , m + 1){
        int dot , len;
        cin >> dot >> len;
        dot = (dot + lastans) % n + 1;
        len = (len + lastans) % n;
        lastans = query(dot , len);
        cout << lastans << endl;
    }
    return 0;
}