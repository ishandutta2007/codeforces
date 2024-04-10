/*input
4 4 1
8
4 1 1
3 1 2
2 1 1
1 1 7
1 2 5
2 2 4
2 3 1
1 3 1
3
ASK 1 1 3 2
SWITCH 1
ASK 1 1 3 2
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
// #define DBGG(i,j)     cout << i << " " << j << endl
// #define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 2020
#define INF 0x3f3f3f3f

int n , m , k;
long long bit[MAX][MAX];
void update(int a , int b , int val){
    for(int i = a ; i < MAX ; i += i & -i)
        for(int j = b ; j < MAX ; j += j & -j)
            bit[i][j] += val;
}
long long query(int a , int b){
    long long res = 0;
    for(int i = a ; i > 0 ; i -= i & -i)
        for(int j = b ; j > 0 ; j -= j & -j)
            res += bit[i][j];
    return res;

}
long long query(int l , int r , int x , int y){
    return query(x , y) - query(l - 1 , y) - query(x , r - 1) + query(l - 1 , r - 1);
}
vector<int> x[MAX] , y[MAX] , v[MAX];
vector<int> ql[MAX] , qr[MAX] , qx[MAX] , qy[MAX] , id[MAX];
long long open[MAX] , ans[MAX];
void solve(){
    REP(i , 0 , k){
        REP(j , 0 , x[i].size()){
            // DB4("update" , x[i][j] , y[i][j] , v[i][j]);
            update(x[i][j] , y[i][j] , v[i][j]);
        }
        REP(j , 0 , ql[i].size()){
            // DBGG("ans = " , query(ql[i][j] , qr[i][j] , qx[i][j] , qy[i][j]));
            ans[id[i][j]] += query(ql[i][j] , qr[i][j] , qx[i][j] , qy[i][j]);
        }
        REP(j , 0 , x[i].size()){
            update(x[i][j] , y[i][j] , -v[i][j]);
        }
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 0 , k){
        int N , a , b , c;
        cin >> N;
        REP(j , 0 , N){
            cin >> a >> b >> c;
            x[i].pb(a) , y[i].pb(b) , v[i].pb(c);
        }
    }
    cin >> n;
    string s;
    REP(i , 0 , k) open[i] = 1;
    int qu = 0;
    REP(i , 0 , n){
        cin >> s;
        if(s == "ASK"){
            int a , b , c , d;
            cin >> a >> b >> c >> d;
            REP(j , 0 , k) if(open[j]){
                ql[j].pb(a);
                qr[j].pb(b);
                qx[j].pb(c);
                qy[j].pb(d);
                id[j].pb(qu);
            }
            qu ++;
        }
        else {
            int tmp;
            cin >> tmp;
            open[tmp - 1] ^= 1;
        }
    }
    solve();
    REP(i , 0 , qu){
        cout << ans[i] << endl;
    }
    return 0;
}