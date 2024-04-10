#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; ++i)
#define REPNM(i,j,k)   for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define endl "\n"
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

string a = "qwertyuiop";
string b = "asdfghjkl;";
string c = "zxcvbnm,./" , q , w , ans;
map<char , char> l , r;
int32_t main(){
	REP(i , a.size()){
		if(i != 0) l[a[i]] = a[i - 1];
		if(i != a.size() - 1) r[a[i]] = a[i + 1];
	}
	REP(i , b.size()){
		if(i != 0) l[b[i]] = b[i - 1];
		if(i != b.size() - 1) r[b[i]] = b[i + 1];
	}
	REP(i , c.size()){
		if(i != 0) l[c[i]] = c[i - 1];
		if(i != c.size() - 1) r[c[i]] = c[i + 1];
	}
	cin >> q >> w;
	REP(i , w.size()){
		if(q == "R") ans += l[w[i]];
		if(q == "L") ans += r[w[i]];
	}
	cout << ans << endl;
    return 0;
}