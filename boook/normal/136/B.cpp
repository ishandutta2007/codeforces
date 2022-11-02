/*input
5 5
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
#define MAX 
#define INF 0x3f3f3f3f

int a , b;
vector<int> aa , bb;
int32_t main(){
	IOS;
	cin >> a >> b;
	while(a) aa.pb(a % 3) , a /= 3;
	while(b) bb.pb(b % 3) , b /= 3;
	while(aa.size() < bb.size()) aa.pb(0);
	while(bb.size() < aa.size()) bb.pb(0);
	vector<int> ans;
	REP(i , 0 , aa.size()){
		int tmp = (bb[i] - aa[i]) % 3;
		ans.pb((tmp + 3) % 3);
	}
	int val = 0 , vv = 1;
	REP(i , 0 , ans.size()){
		val += vv * ans[i] , vv *= 3;
	}
	cout << val << endl;
    return 0;
}