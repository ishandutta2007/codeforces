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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , k , x[MAX];
vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) v[x[i]].pb(i);
    int ans = 0;
    REP(i , 1 , m + 1){
    	int pos = -1;
    	REP(j , 0 , v[i].size()){
    		while(pos + 1 < v[i].size() && (v[i][pos + 1] - v[i][j] + 1) - (pos + 1 - j + 1) <= k) pos ++;
    		ans = max(ans , pos - j + 1);
    	}
    }
    cout << ans << endl;
    return 0;
}