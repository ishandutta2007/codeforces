#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 110
#define INF 0x3f3f3f3f

int n , m;
string s[MAX];
int F(){
	int q = 0 , w = 0 , e = 0;
	REP(i , 0 , n) REP(j , 0 , m){
		if(s[i][j] != s[i][0]) return 0;
		if(s[i][j] == 'R') q = 1;
		if(s[i][j] == 'G') w = 1;
		if(s[i][j] == 'B') e = 1;
	}
	if(q == 0 || w == 0 || e == 0) return 0;
	if(n % 3 != 0) return 0;
	int tmp = n / 3 , fr = n / 3;
	REP(i , 0 , fr) if(s[i][0] != s[0][0]) return 0;
	tmp += fr;
	REP(i , fr , tmp) if(s[i][0] != s[fr][0]) return 0;
	REP(i , tmp , n) if(s[i][0] != s[tmp][0]) return 0;
	return 1;
}
int G(){
	int q = 0 , w = 0 , e = 0;
	REP(i , 0 , n) REP(j , 0 , m){
		if(s[i][j] != s[0][j]) return 0;
		if(s[i][j] == 'R') q = 1;
		if(s[i][j] == 'G') w = 1;
		if(s[i][j] == 'B') e = 1;
	}
	if(q == 0 || w == 0 || e == 0) return 0;
	if(m % 3 != 0) return 0;
	int tmp = m / 3 , fr = m / 3;
	REP(i , 0 , fr) if(s[0][i] != s[0][0]) return 0;
	tmp += fr;
	REP(i , fr , tmp) if(s[0][i] != s[0][fr]) return 0;
	REP(i , tmp , m) if(s[0][i] != s[0][tmp]) return 0;
	return 1;
}
int32_t main(){
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	int q = 1 , w = 1;
	REP(i , 0 , m) if(s[0][i] != s[0][0]) q = 0;
	REP(i , 0 , n) if(s[i][0] != s[0][0]) w = 0;
	if(q == w) cout << "NO" << endl;
	else {
		int ok;
		if(q == 1) ok = F();
		else if(w == 1) ok = G();
		cout << ((ok == 1) ? "YES" : "NO") << endl;
	}  
    return 0;
}