/*input
5
6 6 2 2 2
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 2000000
#define INF 0x3f3f3f3f

int dv[MAX] , p[MAX] , po = 0;
void solveinit(){
	REP(i , 2 , MAX){
		if(dv[i] == 0) dv[i] = i , p[po ++] = i;
		REP(j , 0 , po){
			if(i * p[j] >= MAX) break;
			dv[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
int n , x[MAX] , use[MAX];
int32_t main(){
	IOS;
	solveinit();
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		int ok = 1 , now = x[i];
		vector<int> sol;
		while(now != 1){
			int tmp = dv[now];
			sol.pb(tmp);
			if(use[tmp]) ok = 0;
			while(now % tmp == 0) now /= tmp;
		}
		if(ok){
			for(auto to : sol) use[to] = 1;
		}
		else {
			RREP(ii , MAX - 1 , 2){
				if(use[ii] == 1){
					for(int jj = ii ; jj < MAX ; jj += ii) use[jj] = 1;
				}
			}
			int pos = x[i];
			while(use[pos]) pos ++;
			x[i] = pos;
			for(int jj = pos ; jj < MAX ; jj += pos) use[jj] = 1;
			pos = 2;
			REP(ii , i + 1 , n + 1){
				while(use[pos] || __gcd(x[i] , pos) != 1) pos ++;
				x[ii] = pos;
				for(int jj = pos ; jj < MAX ; jj += pos) use[jj] = 1;
			}
			REP(ii , 1 , n + 1) cout << x[ii] << " " ; cout << endl;
			return 0;
		}
	}
	REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    return 0;
}