/*input
2
XX
OO
XO
OX
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

int n;
vector<string> trs90(vector<string> a){
	vector<string> ans = a;
	REP(i , 0 , n) REP(j , 0 , n) ans[n - 1 - j][i] = a[i][j];
	return ans;
}
vector<string> trs_(vector<string> a){
	vector<string> ans = a;
	REP(i , 0 , n) REP(j , 0 , n) ans[n - 1 - i][j] = a[i][j];
	return ans;
}
vector<string> trsl(vector<string> a){
	vector<string> ans = a;
	REP(i , 0 , n) REP(j , 0 , n) ans[i][n - 1 - j] = a[i][j];
	return ans;
}
vector<string> b;

void check(vector<string> a){
	if(a == b){ cout << "Yes" << endl; exit(0); }
	a = trs_(a);
	if(a == b){ cout << "Yes" << endl; exit(0); }
	a = trsl(a);
	if(a == b){ cout << "Yes" << endl; exit(0); }
	a = trs_(a);
	if(a == b){ cout << "Yes" << endl; exit(0); }
	a = trsl(a);
}
vector<string> a;
string s;
int32_t main(){
	IOS;
	cin >> n;	
	REP(i , 0 , n) cin >> s , a.pb(s);
	REP(i , 0 , n) cin >> s , b.pb(s);
	// a = trs90(a);	
	// a = trs90(a);	
	// a = trs90(a);	
	// a = trs_(a);	
	// if(a == b){ cout << "Yes" << endl; exit(0); }
	// REP(ii , 0 , n) {REP(jj , 0 , n) cout << a[ii][jj] ; cout << endl; }
	// cout << endl;
	// REP(ii , 0 , n) {REP(jj , 0 , n) cout << b[ii][jj] ; cout << endl; }
	REP(i , 0 , 4){
		check(a);
		a = trs90(a);
	}
	cout << "No" << endl;
    return 0;
}