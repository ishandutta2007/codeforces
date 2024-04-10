/*input
1 1 2 0 1 1
5
S
M
S,M
XXL,XXXL
XL,XXL
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
#define MAX 100900
#define INF 0x3f3f3f3f

map<string , int> cc;
int x[6] , sol[MAX] , ans[MAX]; 
vector<PII> v;
string p[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int cmp(int a , int b){ return v[a] < v[b]; }
int32_t main(){
	IOS;
	cc["S"] = 0, cc["M"] = 1 , cc["L"] = 2, cc["XL"] = 3, cc["XXL"] = 4, cc["XXXL"] = 5;
	REP(i , 0 , 6) cin >> x[i];
	int n;
	cin >> n;
	REP(i , 1 , n + 1){
		string s , a , b;
		cin >> s;
		int pos = 0;
		while(pos < s.size() && s[pos] != ',') a += s[pos] , pos ++;
		while(pos < s.size() && s[pos] == ',') pos ++;
		while(pos < s.size() && s[pos] != ',') b += s[pos] , pos ++;
		if(b.size() == 0) v.pb(mp(cc[a] , -1));
		else v.pb(mp(cc[a] , cc[b]));
	}
	REP(i , 0 , v.size()) sol[i] = i;
	sort(sol , sol + v.size() , cmp);
	REP(i , 0 , v.size()){ int id = sol[i];
		if(x[v[id].A]) ans[id] = v[id].A , x[v[id].A] --;
		else if(  v[id].B == -1) return cout << "NO" << endl , 0;
		else if(x[v[id].B]) ans[id] = v[id].B , x[v[id].B] --;
		else return cout << "NO" << endl , 0;
	}
	cout << "YES" << endl;
	REP(i , 0 , v.size()) cout << p[ans[i]] << endl;
    return 0;
}