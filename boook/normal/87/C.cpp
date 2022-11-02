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
#define MAX 100900
#define INF 0x3f3f3f3f

int n , v[MAX];
int32_t main(){
    IOS;
    v[1] = v[2] = 0;
    cin >> n;
    if(n <= 2) return cout << -1 << endl , 0;
    REP(i , 3 , n + 1){
    	map<int , int> cc;
    	REP(j , 2 , i + 1){
    		if(j * (j + 1) / 2 > i) break; 
    		if((i * 2 + j - j * j) % (2 * j) == 0){
    			int fr = (i * 2 + j - j * j) / 2 / j , ba = fr + j - 1;
    			int val = v[ba] ^ v[fr - 1];
    			if(cc.find(val) == cc.end()) cc[val] = j;
    		}
    	}
    	REP(j , 0 , i + 1) if(cc.find(j) == cc.end()){
    		v[i] = v[i - 1] ^ j;
    		break;
    	}
    	if(i != n) continue;
    	if((v[i] ^ v[i - 1]) == 0) cout << -1 << endl;
    	else cout << cc[0] << endl;
    }
    
    return 0;
}