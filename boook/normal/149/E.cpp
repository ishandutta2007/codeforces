/*input

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
#define MAX 200090
#define INF 0x3f3f3f3f

string p , q , s , now;
int n , ans , l , r , fr[MAX] , ba[MAX] , z[MAX];
int32_t main(){
	IOS;
	cin >> p , q = p , reverse(ALL(q));
	cin >> n;
	REP(times , 0 , n){
		REP(i , 0 , p.size()) fr[i] = ba[i] = 0;

		cin >> s;
		if(s.size() == 1) continue;
		now = s + "." + p;
		l = 0 , r = 0 , z[0] = now.size();
		REP(i , 1 , now.size()){
			z[i] = max(min(z[i - l] , r - i + 1) , 0);
			while(i + z[i] < now.size() && now[z[i]] == now[i + z[i]]){
				l = i , r = i + z[i] , z[i] ++;
			}
			if(i > s.size()) fr[i - s.size() + z[i] - 1 - 1] = max(fr[i - s.size() + z[i] - 1 - 1] , z[i]);
		}
		
		reverse(ALL(s));
		now = s + "." + q;
		l = 0 , r = 0 , z[0] = now.size();
		REP(i , 1 , now.size()){
			z[i] = max(min(z[i - l] , r - i + 1) , 0);
			while(i + z[i] < now.size() && now[z[i]] == now[i + z[i]]){
				l = i , r = i + z[i] , z[i] ++;
			}
			if(i > s.size()) ba[i - s.size() + z[i] - 1 - 1] = max(ba[i - s.size() + z[i] - 1 - 1] , z[i]);
		}
		reverse(ba , ba + p.size());
		// REP(i , 0 , p.size()) cout << fr[i]; cout << endl;
		// REP(i , 0 , p.size()) cout << ba[i]; cout << endl;
		REP(i , 1 , p.size()) fr[i] = max(fr[i - 1] , fr[i]);
		RREP(i , p.size() , 0) ba[i] = max(ba[i + 1] , ba[i]);
		REP(i , 0 , p.size()) if(fr[i] + ba[i + 1] >= s.size()){
			ans ++;
			break;
		}
	}
	cout << ans << endl;
    return 0;
}