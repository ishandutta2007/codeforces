/*input
4 2
6 3 8 1
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
#define int long long
#define MAX 200900
#define INF 2000000000000000090LL
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (l + r >> 1)

int mul[MAX * 4];
int n , m , x[MAX] , ba[MAX] , no[MAX] , pre[MAX] , ans = 0;
void build(int now , int l , int r){
    if(l == r) mul[now] = x[l];
    else {
        build(ls , l , mid + 0);
        build(rs , mid + 1 , r);
        if(INF / mul[ls] / mul[rs] == 0) mul[now] = INF;
        else mul[now] = mul[ls] * mul[rs];
    }
}
int query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return mul[now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    else {
        int v1 = query(ls , l , mid + 0 , ql , qr);
        int v2 = query(rs , mid + 1 , r , ql , qr);
        if(INF / v1 / v2 == 0) return INF;
        else return v1 * v2;
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    build(1 , 1 , n);
    REP(i , 1 , n + 1) pre[i] = pre[i - 1] + x[i];

    ba[n] = n + 1 , no[n] = n + 1;
    RREP(i , n - 1 , 1) ba[i] = (x[i + 1] == 1) ? i + 1 : ba[i + 1];
    RREP(i , n - 1 , 1) no[i] = (x[i + 1] != 1) ? i + 1 : no[i + 1];

    int ans = 0;
    REP(now , 1 , n + 1){
        int to = now;
        while(to <= n){
            int sum = (pre[to] - pre[now - 1]) * m;
            int dut = query(1 , 1 , n , now , to);
            if(dut == INF) break;
            if(sum == dut) ans ++ , to ++;
            else if(sum < dut) to += max(1LL , (dut - sum) / m);
            else if(sum > dut) to = no[to];
        }
    }
    cout << ans << endl;
    return 0;
}