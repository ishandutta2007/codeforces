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
#define MAX 200090
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , x[MAX];
vector<int> b[MAX * 4];
void Build(int now , int l , int r){
    if(l == r) b[now].pb(x[l]);
    else {
        Build(ls , l , mid);
        Build(rs , mid + 1 , r);
        b[now].resize(r - l + 1);
        merge(ALL(b[ls]) , ALL(b[rs]) , b[now].begin());
    }
}
int query(int now , int l , int r , int ql , int qr , int k){
    if(ql <= l && r <= qr){
        return upper_bound(ALL(b[now]) , k) - b[now].begin();
    }
    else if(qr <= mid) return query(ls , l , mid , ql , qr , k);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr , k);
    return query(ls , l , mid , ql , qr , k) + query(rs , mid + 1 , r , ql , qr , k);
}
int ans[MAX];
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    Build(1 , 1 , n);
    REP(i , 1 , n + 1){
        REP(j , 1 , n){
            int l = j * (i - 1) + 2;
            int r = min(n , j * i + 1);
            if(l > n) break;
            ans[j] += query(1 , 1 , n , l , r , x[i] - 1);
        }
    }
    REP(i , 1 , n) cout << ans[i] << " " ; cout << endl;
    return 0;
}