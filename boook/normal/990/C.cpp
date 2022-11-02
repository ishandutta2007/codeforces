
 /*input
3
)
()
(
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
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

int n;
string s;
map<int , int> cc;
int32_t main(){
	IOS;
	cin >> n;
	REP(ii , 1 , n + 1){
		cin >> s;
		vector<int> v;
		REP(j , 0 , s.size()){
			if(s[j] == '(') v.pb(-1);
			if(s[j] == ')'){
				if(v.size() != 0 && v.back() == -1) v.pop_back();
				else v.pb(1);
			}
		}
		int siz = v.size();
		if(siz == 0) cc[0] ++;
		else if(v[0] != v.back());
		else if(v[0] < 0) cc[-siz] ++;
		else cc[siz] ++;
	}
	int ans = 0;
	for(auto to : cc){
		if(to.A <= 0) ans += to.B * cc[-to.A];
	}
	cout << ans << endl;
    return 0;
}