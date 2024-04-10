/*input
2 1 2
-1000000000 1000000000
*/
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
#define MAX 200009
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , r[MAX] , p[MAX];
int cmp(int a , int b){
    return x[a] > x[b];
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) r[i] = i;
    sort(r + 1 , r + 1 + n , cmp);
    int ans = 0;
    REP(i , 1 , m * k + 1) p[r[i]] = 1 , ans += x[r[i]];
    // REP(i , 1 , n + 1) cout << p[i] << " "; cout << endl;
    cout << ans << endl;
    REP(i , 1 , n + 1) p[i] += p[i - 1];
    vector<int> tot;
    REP(i , 1 , n + 1) if(p[i] % m == 0 && p[i] > p[i - 1]) tot.pb(i);
    tot.pop_back();
    for(auto to : tot) cout << to << " "; cout << endl;
    return 0;
}