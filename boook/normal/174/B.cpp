/*input
a.b.c
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
#define MAX 
#define INF 0x3f3f3f3f

vector<string> ans;
string s;
void NO(){
	cout << "NO" << endl;
	exit(0);
}
int32_t main(){
	IOS;
	cin >> s;

	int now = 0;
	while(now < s.size()){
		string p;
		REP(i , now , now + 10){
			if(i == s.size()) NO();
			p += s[i];
			if(s[i] == '.'){
				now = i + 1;
				break;
			}
		}
		if(p.size() == 1 || p.size() > 9 || now >= s.size() || s[now] == '.') NO();
		REP(i , 1 , 3 + 1){
			p += s[now ++];
			if(now == s.size() || s[now] == '.') break;
			if(now + 1 < s.size() && s[now + 1] == '.') break;
		}
		ans.pb(p);
	}
	cout << "YES" << endl;
	for(auto to : ans) cout << to << endl;
    return 0;
}