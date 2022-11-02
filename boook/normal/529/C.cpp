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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)
typedef pair<PII , int> PIII;


int b[MAX * 4];

int update(int now , int l , int r , int k , int val){
    if(l == k && r == k) b[now] = val;
    else{
        if(k <= mid) update(ls , l , mid , k , val);
        else update(rs , mid + 1 , r , k , val);
        b[now] = min(b[ls] , b[rs]);
    }
}
int query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return b[now];
    else if(qr <= mid) return query(ls , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return min(query(ls , l , mid , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int cmp1(PII a , PII b){
    return a.B < b.B;
}
int cmp2(PIII a , PIII b){
    return a.A.B < b.A.B;
}
int n , m , k , qust , ans[MAX] , N = 100009;
PIII x[MAX] , y[MAX];
PII a[MAX];
int c[MAX][4];
void solve(){
    sort(a , a + k);
    sort(x , x + qust , cmp2);
    int po = 0;
    REP(i , 0 , qust){
        int id = x[i].B;
        while(po < k && a[po].A <= x[i].A.B)
            update(1 , 1 , N , a[po].B , a[po].A) , po ++;
        int tmp = query(1 , 1 , N , c[id][2] , c[id][3]);
        if(tmp >= x[i].A.A) ans[id] = 1;
    }
    MEM(b , 0);

    sort(a , a + k , cmp1);
    sort(y , y + qust , cmp2);
    po = 0;
    REP(i , 0 , qust){
        int id = y[i].B;
        while(po < k && a[po].B <= y[i].A.B)
            update(1 , 1 , N , a[po].A , a[po].B) , po ++;
        int tmp = query(1 , 1 , N , c[id][0] , c[id][1]);
        if(tmp >= y[i].A.A) ans[id] = 1;
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k >> qust;
    REP(i , 0 , k) cin >> a[i].A >> a[i].B;
    REP(i , 0 , qust){
        cin >> x[i].A.A >> y[i].A.A;
        cin >> x[i].A.B >> y[i].A.B;
        x[i].B = y[i].B = i;
        c[i][0] = x[i].A.A;
        c[i][1] = x[i].A.B;
        c[i][2] = y[i].A.A;
        c[i][3] = y[i].A.B;
    }
    solve();
    REP(i , 0 , qust) cout << ((ans[i] == 1) ? "YES" : "NO") << endl;
    return 0;
}