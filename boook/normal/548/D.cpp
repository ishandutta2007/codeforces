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
#define MAX 300000
#define INF 0x3f3f3f3f

class djs{
public:
    int x[MAX] , l[MAX] , r[MAX] , siz[MAX];
    void init(){
        REP(i , 0 , MAX)
            x[i] = l[i] = r[i] = i , siz[i] = 1;
    }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){
        int q = Find(a) , w = Find(b);
        if(siz[q] > siz[w]) swap(q , w);
        x[q] = w , siz[w] += siz[q];
        r[w] = max(r[w] , r[q]);
        l[w] = min(l[w] , l[q]);
    }
    int operator[](int now){ return Find(now); }
} ds;

int n , x[MAX] , ans[MAX];
vector<int> sol;
int cmp(int a , int b){
    return x[a] > x[b];
}

int32_t main(){
    ds.init();
    cin >> n;
    REP(i , 0 , n){
        cin >> x[i] , sol.pb(i);
    }
    sort(ALL(sol) , cmp);
    for(auto now : sol){
        while(1){
            int top = ds[now] , ok = 0;
            int ll = ds.l[top] - 1 , rr = ds.r[top] + 1;
            if(ll >= 0 && x[now] <= x[ll]) ds.Union(now , ll) , ok = 1;
            if(rr <  n && x[now] <= x[rr]) ds.Union(now , rr) , ok = 1;
            if(ok == 0) break;
        }
        int siz = ds.siz[ds[now]];
        ans[siz] = max(ans[siz] , x[now]);
    }
    RREP(i , n - 1 , 1) ans[i] = max(ans[i] , ans[i + 1]);
    REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}