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
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int n , m , x[MAX];
vector<int> b[MAX * 4];
void Build(int now , int l , int r){
    if(l == r) b[now].pb(x[l]);
    else {
        Build(ls , l , mid);
        Build(rs , mid + 1 , r);
        b[now].resize(r - l + 1);
        merge(b[ls].begin() , b[ls].end() , b[rs].begin() , b[rs].end() , b[now].begin());
    }
}
PII query(int now , int l , int r , int ql , int qr , int q , int w){
    if(ql > qr) return mp(0 , 0);
    if(ql <= l && r <= qr){
        int tma = upper_bound(ALL(b[now]) , w) - b[now].begin();
        int tmb = lower_bound(ALL(b[now]) , q) - b[now].begin();
        return mp(tma , tmb);
    }
    else if(qr <= mid) return query(ls , l , mid , ql , qr , q , w);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr , q , w);
    else {
        PII qq = query(ls , l , mid , ql , qr , q , w);
        PII ww = query(rs , mid + 1 , r , ql , qr , q , w);
        return mp(qq.A + ww.A , qq.B + ww.B);
    }
}
inline long long C(long long now){ return now * (now - 1) / 2; }
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    Build(1 , 1 , n);
    REP(i , 1 , m + 1){
        int l , r , x , y;
        cin >> l >> x >> r >> y;
        long long ans = C(n) - C(l - 1) - C(x - 1) - C(n - r) - C(n - y);
        // DBGG("ans = " , ans);
        PII tma = query(1 , 1 , n , 1 , l - 1 , x , y);
        // DBGG(tma.A , tma.B);
        ans += C((l - 1) - tma.A) + C(tma.B);
        PII tmb = query(1 , 1 , n , r + 1 , n , x , y);
        // DBGG(tmb.A , tmb.B);
        ans += C((n - r) - tmb.A) + C(tmb.B);
        cout << ans << endl;
    }
    return 0;
}