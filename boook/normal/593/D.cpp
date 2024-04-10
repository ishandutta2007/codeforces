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
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int dep[MAX] , pa[MAX] , son[MAX] , siz[MAX];
int top[MAX] , id[MAX] , idpo = 0 , val[MAX];

int n , m , a[MAX][3] , b[MAX * 4];
vector<int> v[MAX];
void DFS1(int now , int fa , int deep){
    dep[now] = deep;
    pa[now] = fa;
    son[now] = 0;
    siz[now] = 1;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS1(to , now , deep + 1);
        if(siz[to] > siz[son[now]]) son[now] = to;
        siz[now] += siz[to];
    }
}
void DFS2(int now , int fa , int root){
    top[now] = root;
    id[now] = ++idpo;
    if(son[now]) DFS2(son[now] , now , root);
    for(auto to : v[now]){
        if(to == fa || to == son[now]) continue;
        DFS2(to , now , to);
    }
}
int N = 1000000000000000009LL;
int mul(int q , int w){
    if(q == -1 || w == -1) return -1;
    if(q == 0 || w == 0) return 0;
    if(N / q / w == 0) return -1;
    return q * w;
}
void Build(int now , int l , int r){
    if(l == r){
        b[now] = val[l] + (val[l] == 0);
    }
    else {
        Build(ls , l , mid + 0);
        Build(rs , mid + 1 , r);
        b[now] = mul(b[ls] , b[rs]);
    }
    // DB4("build = " , l , r , b[now]);
}
void update(int now , int l , int r , int k , int vv){
    if(l == k && r == k) b[now] = vv;
    else{
        if(k <= mid + 0) update(ls , l , mid + 0 , k , vv);
        if(mid + 1 <= k) update(rs , mid + 1 , r , k , vv);
        b[now] = mul(b[ls] , b[rs]);
    }
}
int query(int now , int l , int r , int ql , int qr){
    // cout << "query = " ; DB4("" , "" , ql , qr);
    if(ql <= l && r <= qr) return b[now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return mul(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
void solveinit(){
    DFS1(1 , 0 , 1);
    DFS2(1 , 0 , 1);
    REP(i , 1 , n){
        int q = a[i][0] , w = a[i][1];
        if(dep[q] < dep[w]) val[id[w]] = a[i][2];
        if(dep[q] > dep[w]) val[id[q]] = a[i][2];
    }
    Build(1 , 0 , idpo);
}
int get_val(int l , int r){
    int t1 = top[l] , t2 = top[r] , ans = 1;
    while(t1 != t2){
        if(dep[t1] < dep[t2]) swap(l , r) , swap(t1 , t2);
        // cout << "here" ; DB4(l , r , t1 , ans);
        ans = mul(ans , query(1 , 0 , idpo , id[t1] , id[l]));
        l = pa[t1] , t1 = top[l];
    }
        // cout << "here2" ; DB4(l , r , t1 , ans);
    if(l == r) return ans;
    if(dep[l] < dep[r]) swap(l , r);
    ans = mul(ans , query(1 , 0 , idpo , id[son[r]] , id[l]));
    return ans;
}
void modify(int to , int vv){
    int q = a[to][0] , w = a[to][1];
    if(dep[q] < dep[w]) update(1 , 0 , idpo , id[w] , vv);
    if(dep[q] > dep[w]) update(1 , 0 , idpo , id[q] , vv);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n) REP(j , 0 , 3) cin >> a[i][j];
    REP(i , 1 , n){
        v[a[i][0]].pb(a[i][1]);
        v[a[i][1]].pb(a[i][0]);
    }
    solveinit();
    // cout << "solveinit finish" << endl;
    // REP(i , 1 , n + 1) cout << son[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << dep[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << pa[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << val[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << top[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << id[i] << " " ; cout << endl;
    // exit(0);
    REP(i , 1 , m + 1){
        int ty , p , q , vv;
        cin >> ty;
        if(ty == 1){
            cin >> p >> q >> vv;
            int tmp = get_val(p , q);
            // cout << "the ans = " ;
            if(tmp == -1) cout << 0 << endl;
            else cout << vv / tmp << endl;
        }
        else {
            cin >> p >> vv;
            modify(p , vv);
        }
    }
    return 0;
}