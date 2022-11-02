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
#define MAX 100900
#define INF 0x3f3f3f3f

set<int> cc[MAX];
int n;
int query(int idx , int l , int r){
	auto tmp = cc[idx].lower_bound(l);
	return tmp != cc[idx].end() && (*tmp) <= r;
}
int32_t main(){
    IOS;
    cin >> n;
    REP(times , 1 , n + 1){
    	int ty , x , k , s;
    	cin >> ty;
    	if(ty == 1){
    		cin >> x;
    		REP(i , 1 , x + 1){
    			if(i * i > x) break;
    			else if(x % i == 0) cc[i].insert(x) , cc[x / i].insert(x);
    		}
    	}
    	else {
    		cin >> x >> k >> s;
    		if(x % k != 0) cout << -1 << endl;
    		else {
    			int lim = (s - x) / k;
    			if(lim == 0 || query(k , 1 , s - x) == 0) cout << -1 << endl;
    			else {
    				int l = 1 , r = lim , val = 0 , lw , uw;
    				RREP(j , 20 , 0){
    					if(x & (1 << j)){
    						lw = val;
    						uw = val + (1 << j) - 1;
    						uw = min(uw , s - x);
    						if(query(k , lw , uw) == 0) val ^= (1 << j);
    					}
    					else {
    						lw = val + (1 << j);
    						uw = val + (1 << j) + (1 << j) - 1;
    						uw = min(uw , s - x);
    						if(query(k , lw , uw) == 1) val ^= (1 << j);
    					}
    				}
    				cout << val << endl;
    			}
    		}
    	}
    }
    
    return 0;
}