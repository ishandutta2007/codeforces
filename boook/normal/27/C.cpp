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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , x[MAX] , a[MAX];
int32_t main(){
    IOS;
    cin >> n;
    vector<int> sol;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) if(i == 1 || x[i] != x[i - 1]) sol.pb(i);
    REP(i , 1 , sol.size()) if(x[sol[i]] > x[sol[i - 1]]) a[i] = 1;
    REP(i , 1 , sol.size()) if(x[sol[i]] < x[sol[i - 1]]) a[i] = -1;
    REP(i , 2 , sol.size()) if(a[i] != a[i - 1]){
    	cout << 3 << endl;
    	cout << sol[i - 2] << " " << sol[i - 1] << " " << sol[i] << endl;
    	return 0;
    }
    cout << 0 << endl;
    return 0;
}