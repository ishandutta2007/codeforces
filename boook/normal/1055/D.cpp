/*input
2
a
a


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
#define MAX 3030
#define INF 0x3f3f3f3f

int n , l[MAX] , r[MAX] , ok[MAX];
string s[MAX] , t[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> s[i];
	REP(i , 1 , n + 1) cin >> t[i];
	int G;
	REP(i , 1 , n + 1){
		if(s[i] == t[i]) ok[i] = 1;
		else {
			G = i;
			l[i] = INF , r[i] = -1;
			REP(j , 0 , s[i].size()) if(s[i][j] != t[i][j]){
				l[i] = min(l[i] , j);
				r[i] = max(r[i] , j);
			}
		}
	}
	int fr = 1 , ba = 1;
	REP(i , 1 , n + 1) if(ok[i] == 0 && s[i][r[i]] != s[G][r[G]])
		return cout << "NO" << endl , 0;
	while(1){
		int can = 1;
		REP(i , 1 , n + 1) if(ok[i] == 0){
			if(ok[i] == 0 
				&& r[i] - fr >= 0 
				&& r[i] - fr < s[i].size() 
				&& r[G] - fr >= 0
				&& r[G] - fr < s[G].size()
				&& s[i][r[i] - fr] == s[G][r[G] - fr]);
			else can = 0;
		}
		if(can) fr ++;
		else break;
	}
	while(1){
		int can = 1;
		REP(i , 1 , n + 1) if(ok[i] == 0){
			if(ok[i] == 0 
				&& r[i] + ba >= 0
				&& r[i] + ba < s[i].size() 
				&& r[G] + ba >= 0
				&& r[G] + ba < s[G].size()
				&& s[i][r[i] + ba] == s[G][r[G] + ba]);
			else can = 0;
		}
		if(can) ba ++;
		else break;
	}

	string ss = s[G].substr(r[G] - fr + 1 , fr + ba - 1);
	string tt = t[G].substr(r[G] - fr + 1 , fr + ba - 1);
	// DBGG("ss = " , ss);
	// DBGG("Tt = " , tt);
	// return 0;
	REP(i , 1 , n + 1){
		auto tmp = s[i].find(ss);
		if(tmp == string::npos){
			if(ok[i] == 0) return cout << "NO" << endl , 0;
		}
		else{
			if(t[i].substr(tmp , tt.size()) == tt){
				if(ok[i] == 1);
				else if(tmp <= l[i] && r[i] <= tmp + ss.size() - 1);
				else cout << "NO" << endl , 0;
			}
			else return cout << "NO" << endl , 0;
		}
	}
	cout << "YES" << endl;
	cout << ss << endl;
	cout << tt << endl;
    return 0;
}