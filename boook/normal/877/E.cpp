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
#define MAX 200900
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int sum[MAX * 4] , tag[MAX * 4];
int in[MAX] , out[MAX] , po = 0;
int n , m , x[MAX];
vector<int> v[MAX];

void Push(int now , int l , int r){
    if(tag[now] && l != r){
        tag[ls] ^= 1;
        tag[rs] ^= 1;
        sum[ls] = (mid - l + 1) - sum[ls];
        sum[rs] = (r - (mid + 1) + 1) - sum[rs];
        tag[now] = 0;
    }
}
void update(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        tag[now] ^= 1;
        sum[now] = (r - l + 1) - sum[now];
    }
    else {
        if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr);
        sum[now] = sum[ls] + sum[rs];
    }
}
int query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return sum[now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return query(ls , l , mid + 0 , ql , qr) + query(rs , mid + 1 , r , ql , qr);
}
void DFS(int now){
    in[now] = ++po;
    for(auto to : v[now]) DFS(to);
    out[now] = po;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 2 , n + 1){
        int tmp;
        cin >> tmp;
        v[tmp].pb(i);
    }
    REP(i , 1 , n + 1) cin >> x[i];
    DFS(1);
    REP(i , 1 , n + 1){
        if(x[i]) update(1 , 1 , po , in[i] , in[i]);
    }
//    REP(i , 1 , n + 1) cout <<in[i] <<" " ; cout <<endl;
//    REP(i , 1 , n + 1) cout <<out[i] <<" " ; cout <<endl;
    string s;
    cin >> m;
    REP(i , 1 , m + 1){
        int dot;
        cin >> s >> dot;
        if(s == "get"){
            cout << query(1 , 1 , po , in[dot] , out[dot]) << endl;
        }
        else {
            update(1 , 1 , po , in[dot] , out[dot]);
        }
    }
    return 0;
}