/*input
ilvtbqqllwilvzyzytbw
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
#define int long long
#define MAX 100000
#define INF 0x3f3f3f3f
#define mod 1000000007LL
#define AC 10430579LL

int h[MAX] , c[MAX];
string s;
void solveinit(){
	REP(i , 0 , s.size()){
		h[i + 1] = (h[i] * AC + s[i]) % mod;
	}
}
int query(int l , int len){
	int val = h[l + len] - h[l] * c[len];
	return (val % mod + mod) % mod;
}
int check(int len){
	for(int i = 0 , j = len ; j < s.size() ; i += len , j += len){
		if(s[i] == s[j]){
			int fr = 1 , ba = 1;
			RREP(ii , 18 , 0){
				int to = fr + (1 << ii);
				if(i - to + 1 >= 0 && query(i - to + 1 , to) == query(j - to + 1 , to)) 
					fr = to;
			}
			RREP(ii , 18 , 0){
				int to = ba + (1 << ii);
				if(j + to - 1 < s.size() && query(i , to) == query(j , to))
					ba = to;
			}
			if(ba + fr - 1 >= len) return 1;
		}
	}
	return 0;
}
void solve(int len){
	string g = s.substr(0 , len);
	int po = 0 , val = 0;
	REP(i , len , s.size()){
		g += s[i];
		if(s[i] == g[po]) val ++;
		else val = 0;

		if(val == len){
			REP(j , 0 , len) g.pop_back();
			po -= len , val = 0;
		}
		po ++;
	}
	s = g;
}
int32_t main(){
	IOS;
	cin >> s;
	c[0] = 1;
	REP(i , 1 , s.size() + 1) c[i] = c[i - 1] * AC % mod;
	solveinit();
	REP(i , 1 , s.size() / 2 + 1){
		if(check(i)){
			solve(i);
			solveinit();
		}
	}
	cout << s << endl;
    return 0;
}