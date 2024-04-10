#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(unsigned i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(unsigned i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m;
long long d[MAX] , h[MAX];
long long pre[MAX] , val[MAX];
typedef pair<int , PII> PIII;
PIII b[MAX * 4];
PIII Pull(PIII a , PIII b){
    int val = max(a.A , b.A);
    val = max(val , a.B.A + b.B.B);
    return mp(val , mp(max(a.B.A , b.B.A) , max(a.B.B , b.B.B)));
}
void Build(int now , int l , int r){
    if(l == r){ b[now] = mp(0 , mp(pre[l] , val[l])); }
    else {
        Build(ls , l , mid);
        Build(rs , mid + 1 , r);
        b[now] = Pull(b[ls] , b[rs]);
        // DB4(now , b[now].A , b[now].B.A , b[now].B.B);
    }
}
void solveinit(){
    int tmp = 0;
    REP(i , 1 , n + n + 1) pre[i] = h[i] + tmp , tmp -= d[i] ;//, cout << pre[i] << " "; cout << endl;
    tmp = 0;
    REP(i , 1 , n + n + 1) val[i] = h[i] + tmp , tmp += d[i] ;//, cout << val[i] << " "; cout << endl;
    Build(1 , 1 , n + n);
}
PIII query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return b[now];
    else if(qr <= mid) return query(ls , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    else {
        PIII a = query(ls , l , mid , ql , qr);
        PIII b = query(rs , mid + 1 , r , ql , qr);
        return Pull(a , b);
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> d[i];
    REP(i , 1 , n + 1) cin >> h[i] , h[i] += h[i];
    REP(i , n + 1 , n + n + 1) d[i] = d[i - n] , h[i] = h[i - n];

    solveinit();
    // DBGG("disn = " , b[1].A);

    REP(i , 1 , m + 1){
        int q , w;
        cin >> q >> w;
        if(w == n) cout << query(1 , 1 , n + n , 1 , q - 1).A << endl;
        else if(q > w) cout << query(1 , 1 , n + n , w + 1 , q - 1).A << endl;
        else cout << query(1 , 1 , n + n , w + 1 , n + q - 1).A << endl;
    }
    return 0;
}