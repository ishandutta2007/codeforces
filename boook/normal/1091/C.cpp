/*input
16
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)  for(int i = j ; i < k ; ++i)
#define RREP(i,j,k) for(int i = j ; i >=k ; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i,j) memset(i , j , sizeof i)
#define ALL(i)   i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 0x3f3f3f3f
int n;

int32_t main(){
	IOS;
	cin >> n;
	set<int> in;
	REP(i , 1 , n + 1){
		if(i * i > n) break;
		else if(n % i == 0) in.insert(i) , in.insert(n / i);
	}
	vector<int> ans;
	for(auto to : in){
		int len = n / to;
		int fr = 1 , ba = 1 + (len - 1) * to;
		ans.pb((fr + ba) * len / 2);
	}
	sort(ALL(ans));
	for(auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}