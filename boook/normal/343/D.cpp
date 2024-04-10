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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int b[MAX * 4] , tag[MAX * 4] , add[MAX * 4];
void Push(int now , int l , int r){
    if(l == r) return;
    // zero add
    if(tag[now]){
        tag[ls] = tag[rs] = 1;
        b[ls] = b[rs] = 0;
        add[ls] = add[rs] = 0;
        tag[now] = 0;
    }
    if(add[now]){
        add[ls] += add[now];
        add[rs] += add[now];
        b[ls] += add[now];
        b[rs] += add[now];
        add[now] = 0;
    }
}
void ZERO(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        tag[now] = 1;
        add[now] = 0;
        b[now] = 0;
    }
    else {
        if(ql <= mid + 0) ZERO(ls , l , mid + 0 , ql , qr);
        if(mid + 1 <= qr) ZERO(rs , mid + 1 , r , ql , qr);
    }
}
void ADD(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        add[now] ++;
        b[now] ++;
    }
    else {
        if(ql <= mid + 0) ADD(ls , l , mid + 0 , ql , qr);
        if(mid + 1 <= qr) ADD(rs , mid + 1 , r , ql , qr);
    }
}
int query(int now , int l , int r , int k){
    Push(now , l , r);
    if(l == k && r == k) return b[now];
    else if(k <= mid + 0) return query(ls , l , mid + 0 , k);
    else if(mid + 1 <= k) return query(rs , mid + 1 , r , k);
}
int n , m , po = 1;
int in[MAX] , out[MAX];
vector<int> v[MAX];
void solveinit(int now , int fa){
    in[now] = po ++;
    for(auto to : v[now]){
        if(to == fa) continue;
        solveinit(to , now);
    }
    out[now] = po ++;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n){
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    solveinit(1 , 0);
    // REP(i , 1 , n + 1) cout << in[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << out[i] << " " ; cout << endl;
    cin >> m;
    // ZERO(1 , 1 , po , 1 , po);
    // REP(i , 1 , po) DBGG(i , query(1 , 1 , po , i));
    REP(i , 1 , n + 1) ADD(1 , 1 , po , in[i] , in[i]);
    REP(i , 1 , m + 1){
        int ty , b;
        cin >> ty >> b;
        if(ty == 1){
            ZERO(1 , 1 , po , in[b] , out[b]);
        }
        else if(ty == 2){
            ADD(1 , 1 , po , 1 , in[b]);
        }
        else {
            // DB4("query = " , query(1 , 1 , po , in[b]) , "==" , query(1 , 1 , po , out[b]));
            cout << (query(1 , 1 , po , in[b]) == query(1 , 1 , po , out[b])) << endl;
        }
    }

    return 0;
}