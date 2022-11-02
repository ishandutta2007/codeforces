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
#define MAX 100800
#define INF 0x3f3f3f3f

int n , use[MAX];
PII x[MAX];
vector<int> ans[MAX];
int32_t main(){
    cin >> n;
    REP(i , 0 , n) cin >> x[i].A , x[i].B = i;
    sort(x , x + n);
    int cnt = 0;
    REP(i , 0 , n){
        if(use[i] == 1) continue;
        use[i] = 1 , cnt ++;
        int to = x[i].B;
        ans[i].pb(x[i].B);
        while(to != i){
            ans[i].pb(x[to].B);
            use[to] = 1;
            to = x[to].B;
        }
    }
    cout << cnt << endl;
    REP(i , 0 , n){
        if(ans[i].size()){
            cout << ans[i].size();
            for(auto to : ans[i]) cout << " " << to + 1;
            cout << endl;
        }
    }
    return 0;
}