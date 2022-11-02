/*input
5 10
1 2 0 -1 3
3 1 5 -2 0
2 5
1 3 3 3
2 5
2 4
2 1
1 2 1 4
2 1
2 4
1 4 2 1
2 2
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , a[MAX] , b[MAX];
int add[MAX * 4] , val[MAX * 4];
void Build(int now , int l , int r){
    add[now] = INF;
    if(l == r) val[now] = b[l];
    else {
        Build(ls , l , mid + 0);
        Build(rs , mid + 1 , r);
    }
}
void Push(int now , int l , int r){
    if(add[now] != INF && l != r){
        add[ls] = add[rs] = add[now];
        add[now] = INF;
    }
}
void update(int now , int l , int r , int ql , int qr , int v){
    // if(now == 1) DB4("update" , ql , qr , v);
    Push(now , l , r);
    if(ql <= l && r <= qr) add[now] = v;
    else {
        if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , v);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql,  qr , v); 
    }
}
int query(int now , int l , int r , int k){
    Push(now , l , r);
    if(l == k && r == k) {
        if(add[now] == INF) return val[now];
        else return a[l + add[now]];
    }
    else {
        if(k <= mid + 0) return query(ls , l , mid + 0 , k);
        if(mid + 1 <= k) return query(rs , mid + 1 , r , k);
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    Build(1 , 1 , n);
    REP(i , 1 , m + 1){
        int ty , w , e , r;
        cin >> ty;
        if(ty == 1){
            cin >> w >> e >> r;
            update(1 , 1 , n , e , e + r - 1 , w - e);
        }
        else{
            cin >> w;
            cout << query(1 , 1 , n , w) << endl;
        }
    }
    return 0;
}