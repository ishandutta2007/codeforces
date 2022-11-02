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
#define int long long
#define MAX 100090
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int bit[MAX];
void update(int from , int val){
    // DBGG("update" , from);
    for(int i = from ; i < MAX ; i += i & -i)
        bit[i] ^= val;
}
int query(int from){
    int res = 0;
    for(int i = from ; i > 0 ; i -= i & -i)
        res ^= bit[i];
    return res;
}
int R(){
    int tmp = 0;
    REP(i , 0 , 12) tmp = tmp * 10 + rand() % 10;
    return tmp;
}
typedef pair<PII , PII> QQ;
map<QQ , int> cc;
int n , m , k , x[MAX][5] , ans[MAX] , v[MAX];
void solve(int l , int r){
    // DB4("l = " , l , "r = " , r);
    if(l == r) return ;
    vector<QQ> a , b;
    REP(i , l , r + 1){
        if(x[i][0] != 3 && i <= mid){
            a.pb(mp(mp(x[i][1] , v[i]) , mp(x[i][2] , x[i][4])));
            a.pb(mp(mp(x[i][3] + 1 , v[i]) , mp(x[i][2] , x[i][4])));
        }
        if(x[i][0] == 3 && i > mid){
            b.pb(mp(mp(x[i][3] , x[i][4]) , mp(i , i)));
            b.pb(mp(mp(x[i][1] , x[i][2]) , mp(i , i)));
        }
    }
    sort(ALL(a)) , sort(ALL(b));
    int po = 0;
    for(auto to : b){
        while(po < a.size() && a[po].A.A <= to.A.A){
            update(a[po].B.A , a[po].A.B);
            update(a[po].B.B + 1 , a[po].A.B);
            po ++;
        }
        ans[to.B.A] ^= query(to.A.B);
    }
    while(po < a.size()){
        update(a[po].B.A , a[po].A.B);
        update(a[po].B.B + 1 , a[po].A.B);
        po ++;
    }
    // REP(i , 0 , k) cout << ans[i] << " "; cout << endl;
    solve(l , mid);
    solve(mid + 1 , r);
}
int32_t main(){
    IOS;
    srand(time(NULL));
    cin >> n >> m >> k;
    REP(i , 0 , k){ 
        REP(j , 0 , 5) cin >> x[i][j];
        if(x[i][0] != 3){
            QQ tmp = mp(mp(x[i][1] , x[i][2]) , mp(x[i][3] , x[i][4]));
            if(cc.find(tmp) == cc.end()) cc[tmp] = R();
            v[i] = cc[tmp];
            // DB4("random" , "i = " , i , cc[tmp]);
        }
    }
    solve(0 , k - 1);
    REP(i , 0 , k){
        if(x[i][0] == 3){
            if(ans[i] == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}