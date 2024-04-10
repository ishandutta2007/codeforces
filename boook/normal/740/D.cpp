/*input
5
2 5 1 4 6
1 7
1 1
3 5
3 6
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
#define int long long
#define MAX 400900
#define INF 0x3f3f3f3f

int bit[MAX];
void update(int from , int val){
    for(int i = from + 10 ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int res = 0;
    for(int i = from + 10 ; i > 0 ; i -= i & -i)
        res += bit[i];

    return res;
}
int n , val[MAX] , dep[MAX] , siz[MAX] , son[MAX] , ans[MAX];
vector<PII> v[MAX];
void DFS1(int now , int deep){
    dep[now] = deep;
    siz[now] = 1;
    int big = 0;
    son[now] = 0;
    for(auto to : v[now]){
        DFS1(to.A , deep + to.B);
        siz[now] += siz[to.A];
        if(big < siz[to.A]) big = siz[to.A] , son[now] = to.A;
    }
}
void DFS3(int now , int vv){
    update(val[now] , vv);
    for(auto to : v[now]) DFS3(to.A , vv);
}
void DFS2(int now , int ty){
    for(auto to : v[now]) if(to.A != son[now]) DFS2(to.A , 0);

    if(son[now]) DFS2(son[now] , 1);

    for(auto to : v[now]) if(to.A != son[now]) DFS3(to.A , 1);

    ans[now] = query(dep[now]);

    if(ty == 0) for(auto to : v[now]) DFS3(to.A , -1);
    if(ty == 1) update(val[now] , 1);
}
int32_t main(){
    IOS , cin >> n;
    REP(i , 1 , n + 1) cin >> val[i];
    REP(i , 2 , n + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(mp(i , b));
    }
    DFS1(1 , 0);
    vector<int> uni;
    REP(i , 1 , n + 1) val[i] = dep[i] - val[i];
    REP(i , 1 , n + 1) uni.pb(val[i]);
    REP(i , 1 , n + 1) uni.pb(dep[i]);
    sort(ALL(uni));
    uni.resize(unique(ALL(uni)) - uni.begin());
    REP(i , 1 , n + 1) val[i] = lower_bound(ALL(uni) , val[i]) - uni.begin();
    REP(i , 1 , n + 1) dep[i] = lower_bound(ALL(uni) , dep[i]) - uni.begin();

    DFS2(1 , 0);
    REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}