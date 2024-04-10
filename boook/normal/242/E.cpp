/*input
6
4 7 4 0 7 3
5
2 2 3 8
1 1 5
2 3 5 1
2 4 5 6
1 2 3
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
#define MAX 100900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int sum[26][MAX * 4] , tag[26][MAX * 4];
int n , m , x[MAX];
void build(int now , int l , int r , int ty){
    if(l == r) sum[ty][now] = !!(x[l] & (1 << ty));
    else {
        build(ls , l , mid + 0 , ty);
        build(rs , mid + 1 , r , ty);
        sum[ty][now] = sum[ty][ls] + sum[ty][rs];
    }
}
void Push(int now , int l , int r , int ty){
    if(tag[ty][now] != 0 && l != r){
        tag[ty][ls] ^= 1;
        tag[ty][rs] ^= 1;
        sum[ty][ls] = (mid - l + 1) - sum[ty][ls];
        sum[ty][rs] = (r - (mid + 1) + 1) - sum[ty][rs];
        tag[ty][now] ^= 1;
    }
}
void update(int now , int l , int r , int ty , int ql , int qr){
    Push(now , l , r , ty);
    if(ql <= l && r <= qr){
        tag[ty][now] ^= 1;
        sum[ty][now] = (r - l + 1) - sum[ty][now];
    }
    else {
        if(ql <= mid + 0) update(ls , l , mid + 0 , ty , ql , qr);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ty , ql , qr);
        sum[ty][now] = sum[ty][ls] + sum[ty][rs];
    }
}
int query(int now , int l , int r , int ty , int ql , int qr){
    Push(now , l , r , ty);
    if(ql <= l && r <= qr) return sum[ty][now];
    else if(qr <= mid + 0) return query(ls , l , mid + 0 , ty , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ty , ql , qr);
    return query(ls , l , mid + 0 , ty , ql , qr) + query(rs , mid + 1 , r , ty , ql , qr);
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];

    REP(i , 0 , 25) build(1 , 1 , n , i); 

    cin >> m;
    REP(times , 1 , m + 1){
        int ty , l , r , v;
        cin >> ty;
        if(ty == 1){
            cin >> l >> r;
            int res = 0;
            REP(i , 0 , 25){
                // DBGG(i , query(1 , 1 , n , i , l , r));
                res += query(1 , 1 , n , i , l , r) * (1 << i);
            }
            cout << res << endl;
        }
        else {
            cin >> l >> r >> v;
            REP(i , 0 , 25){
                if(v & (1 << i)) update(1 , 1 , n , i , l , r);
            }
        }
    }
    return 0;
}