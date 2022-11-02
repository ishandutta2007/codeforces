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
#define MAX 
#define INF 0x3f3f3f3f

int n , a , b;
string s;
vector<int> v;
void solve(){
	cout << v.size() << endl;
	REP(i , 0 , v.size()){
		int now = v[i];
		string tmp = s.substr(0 , now);
		s = s.substr(now);
		cout << tmp << endl;
	}
}
int32_t main(){
	cin >> n >> a >> b;
	cin >> s;
	for(int i = 0 ; i * a <= n ; i ++){
		int tmp = n - i * a;
		if(tmp % b == 0){
			int times = tmp / b;
			REP(j , 0 , i) v.pb(a);
			REP(j , 0 , times) v.pb(b);
			solve();
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}