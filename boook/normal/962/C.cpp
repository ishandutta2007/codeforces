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
#define int long long
#define INF 1000000000000000LL


string s;
set<int> cc;
int32_t main(){
    IOS;
    cin >> s;
    REP(i , 1 , 100000) cc.insert(i * i);
    int n = s.size() , ans = INF;
    REP(i , 1 , (1 << n)){
    	int val = 0 , can = 0 , ok = 1 , cnt = 0;
    	REP(j , 0 , n){
    		if(i & (1 << j)){
    			cnt ++;
    			if(s[j] == '0' && can == 0) ok = 0;
    			val = val * 10 + s[j] - '0';
    			can = 1;
    		}
    	}
    	if(ok && cc.find(val) != cc.end()) ans = min(ans , n - cnt);
    }
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;    
    return 0;
}