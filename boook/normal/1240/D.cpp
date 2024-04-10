#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

int t , n , xx[MAX] , to[MAX] , dp[MAX];
struct djs{
    int id[MAX];
    map<int , int> cc[MAX];
    void init(){
        REP(i , 1 , n + 2) cc[i].clear();
        REP(i , 1 , n + 1) id[i] = i , cc[i][xx[i]] = i;
    }
    int Find(int a){
        return a == id[a] ? a : id[a] = Find(id[a]); 
    }
    void Union(int a , int b){
        a = Find(a) , b = Find(b);
        if(cc[a].size() < cc[b].size()) swap(a , b);
        id[b] = a;
        for(auto to : cc[b]){
            if(cc[a].find(to.F) == cc[a].end())
                cc[a][to.F] = to.S;
            else cc[a][to.F] = min(cc[a][to.F] , to.S);
        }
    }
    int operator[](int a){ return Find(a); }
} ds;

int32_t main(){
    IOS;
    cin >> t;
    REP(times , 0 , t){
        cin >> n;
        REP(i , 1 , n + 2) to[i] = dp[i] = 0;

        REP(i , 1 , n + 1) cin >> xx[i];

        ds.init();


        RREP(i , n - 1 , 1){
            int idx = ds[i + 1];
            // DBGG(i , idx);
            // REP(j , 1 , n + 1) if(ds[j] == ds[idx]) cout << j << "-"; cout << endl;
            if(ds.cc[idx].find(xx[i]) != ds.cc[idx].end()){
                int val = ds.cc[idx][xx[i]];
                // DBGG("val = " , val);
                if(val != n) ds.Union(i , val + 1);
                to[i] = val + 1;
                // DBGG(i , to[i]);
            }
        }
        int ans = 0;
        RREP(i , n , 1){
            if(to[i] == 0) dp[i] = 0;
            else dp[i] = dp[to[i]] + 1;
            ans += dp[i];
        }
        cout << ans << endl;
    }
    return 0;
}