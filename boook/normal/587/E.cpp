/*input
10 1
511 3072 28 1 0 0 2 29 4603 7
2 6 10
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
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int bit[MAX];
int n , m , x[MAX];
vector<int> v[MAX * 4];

void update(int from , int val){
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] ^= val;
}
int query(int from){
    int cnt = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        cnt ^= bit[i];
    return cnt;
}
vector<int> pull(vector<int> a , vector<int> b){
    for(auto val : b){
        for(auto to : a) val = min(val , val ^ to);
        if(val) a.pb(val);
    }
    return a;
}
void build(int now , int l , int r){
    if(l == r){
        if(x[l] ^ x[l + 1]) v[now].pb(x[l] ^ x[l + 1]);
    }
    else {
        build(ls , l , mid + 0);
        build(rs , mid + 1 , r);
        v[now] = pull(v[ls] , v[rs]);
    }
    // DBGG("now = " , now);
    // for(auto to : v[now]) cout << to << " "; cout << endl;
}
void update(int now , int l , int r , int k , int val){
    if(l == r){
        if(v[now].size() == 0) v[now].pb(val);
        else v[now][0] ^= val;
        if(v[now].back() == 0) v[now].pop_back();
    }
    else {
        if(k <= mid + 0) update(ls , l , mid + 0 , k , val);
        if(mid + 1 <= k) update(rs , mid + 1 , r , k , val);
        v[now] = pull(v[ls] , v[rs]);
    }
}
vector<int> query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return v[now];
    if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) update(i , x[i]) , update(i + 1 , x[i]);
    build(1 , 0 , n);
    REP(i , 1 , m + 1){
        int ty , l , r , k;
        cin >> ty;
        if(ty == 1){
            cin >> l >> r >> k;
            update(1 , 0 , n , l - 1 , k);
            update(1 , 0 , n , r - 0 , k);
            update(l + 0 , k);
            update(r + 1 , k);
        }
        if(ty == 2){
            cin >> l >> r;
            int val = query(l);
            if(l == r) cout << (val == 0 ? 1 : 2) << endl;
            else {
                // DBGG("val = " , val);
                vector<int> a(1 , val);
                vector<int> b = query(1 , 0 , n , l , r - 1);
                cout << (1LL << pull(b , a).size()) << endl;
            }
        }
    }
    return 0;
}