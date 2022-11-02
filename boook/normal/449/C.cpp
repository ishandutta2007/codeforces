#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   push_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

int n , use[MAX];
vector<PII> ans;
int32_t main(){
    cin >> n;
    REP(i , 3 , n + 1){
        if(use[i] || i % 2 == 0) continue;
        else {
            vector<int> sol;
            for(int j = i + i + i ; j <= n ; j += i){
                if(use[j] == 0) sol.pb(j);
            }
            if(sol.size() % 2 == 0 && i + i <= n) sol.pb(i) , sol.pb(i + i);
            else sol.pb(i);
            for(int j = 1 ; j < sol.size() ; j += 2){
                ans.pb(mp(sol[j - 1] , sol[j]));
                use[sol[j - 1]] = 1;
                use[sol[j - 0]] = 1;
            }
        }
    }
    vector<int> sol;
    REP(i , 2 , n + 1){
        if(i % 2 == 0 && use[i] == 0) sol.pb(i);
    }
    for(int j = 1 ; j < sol.size() ; j += 2){
        ans.pb(mp(sol[j - 1] , sol[j]));
    }
    cout << ans.size() << endl;
    for(auto to : ans){
        cout << to.A << " " << to.B << endl;
    }
    return 0;
}