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
#define MAX 800900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int b[MAX * 4] , tag[MAX * 4] , col[MAX];
void Build(int now , int l , int r){
    if(l == r) b[now] = col[l];
    else {
        Build(ls , l , mid + 0);
        Build(rs , mid + 1 , r);
        b[now] = b[ls] | b[rs];
    }
}
void Push(int now , int l , int r){
    if(tag[now] && l != r){
        b[ls] = tag[now];
        b[rs] = tag[now];
        tag[ls] = tag[now];
        tag[rs] = tag[now];
        tag[now] = 0;
    }
}
void update(int now , int l , int r , int ql , int qr , int val){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        b[now] = val;
        tag[now] = val;
    }
    else{
        if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
        b[now] = b[ls] | b[rs];
    }
}
int query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return b[now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return query(ls , l , mid + 0 , ql , qr) | query(rs , mid + 1 , r , ql , qr);
}
int n , m , x[MAX] , in[MAX] , out[MAX] , po = 1;
vector<int> v[MAX];
void DFS(int now , int fa){
    in[now] = po ++;
    for(auto to : v[now]){
        if(to == fa) continue;
        DFS(to , now);
    }
    out[now] = po ++;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 2 , n + 1){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    DFS(1 , 0);
    REP(i , 1 , n + 1) col[in[i]] = col[out[i]] = (1LL << x[i]);
    Build(1 , 1 , po);
    // REP(i , 1 , n + 1) cout << in[i] << " " ;cout << endl;
    // REP(i , 1 , n + 1) cout << out[i] << " " ; cout << endl;
    REP(i , 1 , m + 1){
        int ty , a , b;
        cin >> ty >> a;
        if(ty == 1){
            cin >> b;
            update(1 , 1 , po , in[a] , out[a] , (1LL << b));
        }
        else {
            int ans = query(1 , 1 , po , in[a] , out[a]);
            // cout << "the ans = ";
            bitset<70> tmp(ans);
            cout << tmp.count() << endl;
        }
    }
    return 0;
}