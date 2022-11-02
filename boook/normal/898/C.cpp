/*input
2
ivan 1 00123
masha 1 00123
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

map<string , vector<string>> cc;
int32_t main(){
	IOS;
	int n; cin >> n;
	REP(i , 1 , n + 1){
		string ss , s;
		cin >> ss;
		int in; cin >> in;
		REP(j , 0 , in){
			cin >> s;
			cc[ss].pb(s);
		}
	}
	cout << cc.size() << endl;
	for(auto to : cc){
		vector<string> now = to.B;
		REP(i , 0 , now.size()){
			REP(j , 0 , now.size()){
				if(i == j) continue;
				if(now[j].size() <= now[i].size()){
					int ok = 1 , aa = now[i].size() , bb = now[j].size();
					REP(jj , 0 , bb){
						if(now[i][aa - 1 - jj] != now[j][bb - 1 - jj]) ok = 0;
					}
					if(ok) now[j] = "!";
				}
			}
		}
		int cnt = 0;
		REP(i , 0 , now.size()){
			if(now[i] != "!") cnt ++;
		}
		cout << to.A << " " << cnt << " ";
		REP(i , 0 , now.size()){
			if(now[i] != "!") cout << now[i] << " ";
		}
		cout << endl;
	}
    return 0;
}