/*input
abcd
7
1
1 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 100000
#define INF 0x3f3f3f3f

string s;
crope cc;
int n , m , ql[MAX] , qr[MAX];

crope solve(int idx , int lim){
	// DBGG(idx , lim);
	if(idx == 0) return cc.substr(0 , lim);
	int len = qr[idx] - ql[idx] + 1	, sml;
	if(qr[idx] + 1 >= lim) sml = 0;
	else if(qr[idx] + len >= lim) sml = lim - qr[idx] - 1;
	else sml = len;
	// DBGG("sml = " , sml);
	int pos = ql[idx] == qr[idx] ? ql[idx] : ql[idx] + 1;

	crope val = solve(idx - 1 , lim - sml);
	// cout << val.c_str() << endl;
	s.clear();
	REP(i , 0 , sml){
		if(pos >= val.size()) exit(0);
		s += val[pos];
		pos = pos + 2 > qr[idx] ? ql[idx] : pos + 2;
	}
	val.insert(qr[idx] + 1 , s.c_str());
	return val;
}
int32_t main(){
	IOS;
	cin >> s >> m >> n , cc = s.c_str();
	REP(i , 1 , n + 1) cin >> ql[i] >> qr[i] , ql[i] -- , qr[i] --;
	cout << solve(n , m).c_str() << endl;
    return 0;
}