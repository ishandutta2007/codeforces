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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x , d , a[MAX] , b[MAX];
int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
int initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
class djs{
public:
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return x[now] == now ? now : x[now] = Find(x[now]); }
    void Union(int q , int w){ x[Find(q)] = Find(w); }
    int operator[](int now){ return Find(now); }
} ds;
int sol[MAX] , ans[MAX] , nxt[MAX];
int cmp(int q , int w){  return a[q] > a[w];  }
void solve(){
    REP(i , 0 , n) sol[i] = i;
    sort(sol , sol + n , cmp);
    REP(id , 0 , n){
        // DB4("now sol = " , a[sol[id]] , "dol = " , sol[id]);
        int i = sol[id] , now = i;
        int v1 = nxt[0] , v2 = ds[i];
        while(max(i + v1 , v2) < n){
            // DB4("v1 = " , i + v1 , "v2 = " , v2);
            // DB4("ds[v2]" , ds[v2] , v2 , ds[ds[v2] + 1]);   
            if(i + v1 == v2){
                ans[v2] = a[i];
                ds.Union(v2 , v2 + 1);
                v1 = nxt[v1 + 1];
                v2 = (v2 == ds[v2]) ? ds[ds[v2] + 1] : ds[v2];
            }
            else if(i + v1 < v2) v1 = nxt[v2 - i];
            else if(i + v1 > v2) v2 = ds[i + v1];
        }
    }
}
int32_t main(){
    cin >> n >> d >> x;
    initAB();
    // REP(i , 0 , n) cout << a[i] << " "; cout << endl;
    // REP(i , 0 , n) cout << b[i] << " "; cout << endl;
    int tmp = n + 1;
    RREP(i , n + 1 , 0){
        if(b[i]) tmp = i;
        nxt[i] = tmp;
    }
    ds.init();
    solve();
    REP(i , 0 , n) cout << ans[i] << endl;
    return 0;
}