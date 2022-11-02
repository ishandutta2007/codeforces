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
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , m , id[MAX] , o[MAX];
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
} ds;
int32_t main(){

    ds.init();
    cin >> n >> m;
    if(m == 0){
        int ans = 1;
        REP(i , 1 , n) ans = ans * 2 % mod;
        cout << ans << endl;
    }
    else{
        int ans = 1 , cnt = 0;
        REP(i , 0 , m){
            int q , w , e;
            cin >> q >> w >> e;
            o[q] ++ , o[w] ++;
            if(e == 1){
                if(ds[q * 2] == ds[w * 2 + 1]) ans = 0;
                ds.Union(q * 2 , w * 2);
                ds.Union(q * 2 + 1 , w * 2 + 1);
            }
            else {
                if(ds[q * 2] == ds[w * 2]) ans = 0;
                ds.Union(q * 2 + 1 , w * 2);
                ds.Union(q * 2 , w * 2 + 1);
            }
        }
        REP(i , 1 , n + 1) if(ds[i * 2] == i * 2) cnt ++;
        REP(i , 1 , cnt) ans = ans * 2 % mod;
        cout << ans << endl;
    }
    return 0;
}