/*input
8 5 5
1 1 1 2 2 2 1 1
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
#define pb   push_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f

int n , m , k , x[MAX];
vector<PII> sol;
int32_t main(){
	cin >> n >> m >> k;

	REP(i , 1 , n + 1){
		cin >> x[i];
		if(sol.size() == 0 || sol.back().A != x[i]) sol.pb(mp(x[i] , 1));
		else {
			int tmp = sol.back().B;
			sol.pb(mp(x[i] , tmp + 1));
			if(sol.back().B >= m){
				REP(j , 0 , m) sol.pop_back();
			}
		}
	}
	if(sol.size() == 0){
		cout << 0 << endl;
	}
	else if(sol.back().B == sol.size()){
		int sum = sol.size() * k;
		cout << sum % m << endl;
	}
	else {
		deque<int> vv;
		REP(i , 0 , sol.size()) vv.push_back(sol[i].A);

		int tma = sol.size();
		REP(i , 1 , n + 1){
			if(sol.size() == 0 || sol.back().A != x[i]) sol.pb(mp(x[i] , 1));
			else {
				int tmp = sol.back().B;
				sol.pb(mp(x[i] , tmp + 1));
				if(sol.back().B >= m){
					REP(j , 0 , m) sol.pop_back();
				}
			}
			// for(auto to : sol) cout << to.A << " " ;cout << endl;
		}
		int tmb = sol.size();
		if(sol.size() == 0){
			if(k % 2 == 0) cout << 0 << endl;
			else cout << tma << endl;
		}
		else {
			int fr = 0 , ba = 0;
			while(vv.size() > m){
				int ff = vv[0] , ok = 0 , l = 0 , r = vv.size() - 1;
				while(vv[l] == ff && ok < m && l <= r) l ++ , ok ++;
				while(vv[r] == ff && ok < m && l <= r) r -- , ok ++;
				if(ok < m) break;
				REP(j , 0 , m){
					if(vv.front() == ff) vv.pop_front() , fr ++;
					else vv.pop_back() , ba ++;
				}
			}
			int ok = 1;
			REP(i , 0 , vv.size()) if(vv[i] != vv[0]) ok = 0;
			// DB4("fr = " , fr , "ba = " , ba);
			// DBGG("mid = " , tma - fr - ba);
			if(ok == 1){
				int mid = (tma - fr - ba) * k % m;
				if(mid == 0) cout << 0 << endl;
				else cout << mid + fr + ba << endl;
			}
			else {
				int mid = tma - fr - ba;
				cout << fr + ba + mid * k << endl;
			}
		}
 	}
    return 0;
}