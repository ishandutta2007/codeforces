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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , s[MAX];
vector<int> v[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , m + 1){
    	int a , b;
    	cin >> a >> b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    REP(times , 0 , INF){
    	int ok = 1;
    	REP(i , 1 , n + 1){
    		int cnt = 0;
    		for(auto to : v[i]) cnt += s[i] == s[to];
    		if(cnt > 1) s[i] ^= 1 , ok = 0;
    	}
    	if(ok) break;
    }
    REP(i , 1 , n + 1) cout << s[i] ; cout << endl;
    return 0;
}