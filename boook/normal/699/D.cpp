/*input
8
2 3 5 4 1 6 6 7
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

struct djs{
    int x[MAX];
    void init(){ REP(i , 0 , MAX) x[i] = i; }
    int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int now){ return Find(now); }
} ds;
int n , x[MAX] , ans[MAX];
int32_t main(){
    IOS , ds.init();
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1){
        if(ds[i] != ds[x[i]]){
            ds.Union(i , x[i]);
            ans[i] = x[i];
        }
    }
    int id = -1;
    REP(i , 1 , n + 1){
        if(ans[i] == 0){
            id = i;
            if(x[i] == i) break;
        }
    }
    REP(i , 1 , n + 1){
        if(ans[i] == 0) ans[i] = id;
    }
    int cnt = 0;
    REP(i , 1 , n + 1) if(x[i] != ans[i]) cnt ++;
    cout << cnt << endl;
    REP(i , 1 , n + 1) cout << ans[i] << " " ; cout << endl;
    return 0;
}