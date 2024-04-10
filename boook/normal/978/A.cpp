/*input
5
2 4 2 4 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1000
#define INF 0x3f3f3f3f

int n , x[MAX];
vector<int> fr , ba;
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    reverse(x + 1 , x + 1 + n);
    set<int> cc;
    REP(i , 1 , n + 1) if(cc.count(x[i]) == 0) cc.insert(x[i]) , fr.pb(x[i]);
    cout << fr.size() << endl;
    reverse(ALL(fr));
    for(auto to : fr) cout << to << " " ; cout << endl;
    
    return 0;
}