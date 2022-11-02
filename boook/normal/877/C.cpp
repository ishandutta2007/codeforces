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
#define MAX 5050

int n;
int32_t main(){
    IOS , cin >> n;
    vector<int> ans;

    for(int i = 2 ; i <= n ; i += 2) ans.pb(i);
    for(int i = 1 ; i <= n ; i += 2) ans.pb(i);
    for(int i = 2 ; i <= n ; i += 2) ans.pb(i);
    cout << ans.size() << endl;
    for(auto to : ans) cout << to << " "; cout << endl;
    return 0;
}