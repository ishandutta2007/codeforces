#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
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

int n , m , k;
int x[7][MAX];
int b[7][MAX * 4];
void Build(int ty , int now , int l , int r){
    if(l == r){ b[ty][now] = x[ty][l]; }
    else {
        Build(ty , ls , l , mid);
        Build(ty , rs , mid + 1 , r);
        b[ty][now] = max(b[ty][ls] , b[ty][rs]);
    }
}
int query(int ty , int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return b[ty][now];
    else if(qr <= mid) return query(ty , ls , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(ty , rs , mid + 1 , r , ql , qr);
    else return max(query(ty , ls , l , mid , ql , qr) ,
                    query(ty , rs , mid + 1 , r , ql , qr));
}
int ans[10];
int mm = 0;
void solve(){
    REP(i , 0 , n){
        int tmp = 0 , now = i;
        REP(j , 0 , m) tmp += x[j][i];
        if(tmp > k) continue;



        RREP(j , 20 , 0){
            int to = now + (1LL << j) , cnt = 0;
            if(to >= n) continue;
            else {
                REP(k , 0 , m) {
                    cnt += query(k , 1 , 0 , n - 1 , i , to);
                }
                if(cnt <= k) now = to;
            }
        }
        if(now - i + 1 > mm){
            mm = now - i + 1;
            REP(k , 0 , m) ans[k] = query(k , 1 , 0 , n - 1 , i , now);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , n) REP(j , 0 , m)
        cin >> x[j][i];
    REP(i , 0 , m) Build(i , 1 , 0 , n - 1);
    solve();
    REP(i , 0 , m) cout << ans[i] << " " ; cout << endl;
    return 0;
}