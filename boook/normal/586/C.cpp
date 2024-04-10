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
#define MAX 5050
#define INF 0x3f3f3f3f

int n , v[MAX] , d[MAX] , p[MAX] , use[MAX];
int32_t main(){
    cin >> n;
    REP(i , 1 , n + 1) cin >> v[i] >> d[i] >> p[i];
    vector<int> ans;
    REP(i , 1 , n + 1){
        queue<int> fk;
        if(p[i] >= 0){
            ans.pb(i);
            REP(j , i + 1 , n + 1){
                if(p[j] < 0) continue;
                p[j] -= v[i]--;
                if(v[i] == 0) break;
                if(p[j] < 0 && use[j] == 0) use[j] = 1 , fk.push(j); 
            }
        }
        while(fk.size()){
            int id = fk.front(); fk.pop();
            REP(j , id + 1 , n + 1){
                p[j] -= d[id];
                if(p[j] < 0 && use[j] == 0) use[j] = 1 , fk.push(j);
            }
        }
        // REP(j , 1 , n + 1) cout << p[j   ] << " "; cout << endl;
    }
    cout << ans.size() << endl;
    for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}