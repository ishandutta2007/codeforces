/*input
3 2
1 3 3
1 3 2
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

int n , m , x[MAX][3] , tag[MAX * 4] , val[MAX * 4];
int Push(int now , int l , int r){
    if(l != r && tag[now]){
        tag[ls] |= tag[now];
        tag[rs] |= tag[now];
        val[ls] |= tag[now];
        val[rs] |= tag[now];
        tag[now] = 0;
    }
}
void update(int now , int l , int r , int ql , int qr , int v){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        val[now] |= v;
        tag[now] |= v;
    }
    else {
        if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , v);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , v);
    }
}
void Build(int now , int l , int r){
    Push(now , l , r);
    if(l == r) return;
    else {
        Build(ls , l , mid + 0);
        Build(rs , mid + 1 , r);
        val[now] = val[ls] & val[rs];
    }
}
int query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return val[now];
    if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return (query(ls , l , mid + 0 , ql , qr) & query(rs , mid + 1 , r , ql , qr));
}
void Print(int now , int l , int r){
    if(l == r) cout << val[now] << " ";
    else Print(ls , l , mid + 0) , Print(rs , mid + 1 , r);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 0 , m) REP(j , 0 , 3) cin >> x[i][j];
    REP(i , 0 , m) update(1 , 1 , n , x[i][0] , x[i][1] , x[i][2]);
    Build(1 , 1 , n);
    REP(i , 0 , m) if(query(1 , 1 , n , x[i][0] , x[i][1]) != x[i][2])
        return cout << "NO" << endl , 0;
    cout << "YES" << endl;
    Print(1 , 1 , n) , cout << endl;
    return 0;
}