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
#define MAX 400900
#define INF 0x3f3f3f3f

int n , w , h;
class N{
public:
    int x , y , val , id;
    N(int a , int b , int c , int d){
        x = a , y = b , val = c , id = d;
    }
};
vector<N> b , tt;
vector<int> v[MAX];
queue<int> a[MAX];
int cmp(N a , N b){
    if(a.val != b.val) return a.val < b.val;
    else return a.x < b.x;
}
PII ans[MAX];
void solve(){
    sort(ALL(b) , cmp);
    REP(i , 0 , b.size()){
        if(a[b[i].val].size()){
            int id = b[i].val;
            int tmp = a[id].front();
            a[id].pop();
            ans[tmp] = mp(w , b[i].x);
            a[id].push(b[i].id);
        }
        else ans[b[i].id] = mp(w , b[i].x);
    }
}
int K = 100009;
int32_t main(){
    IOS;
    cin >> n >> w >> h;
    REP(i , 0 , n){
        int q , w , e;
        cin >> q >> w >> e;
        if(q == 1){
            tt.pb(N(w , e , e - w + K , i));    
        }
        if(q == 2) b.pb(N(w , e , e - w + K , i));
    }
    sort(ALL(tt) , cmp);
    RREP(i , tt.size() - 1 , 0){
        a[tt[i].val].push(tt[i].id);
    }
    REP(i , 0 , tt.size()){
        v[tt[i].val].pb(tt[i].x);
    }
    solve();
    REP(i , 0 , MAX){
        if(a[i].size()){
            RREP(j , a[i].size() - 1 , 0){
                ans[a[i].front()] = mp(v[i][j] , h);
                a[i].pop();
            }
        }
    }
    REP(i , 0 , n){
        cout << ans[i].A << " " << ans[i].B << endl;
    }
    return 0;
}