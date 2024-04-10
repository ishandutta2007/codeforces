/*input
2 10
codeforces
codeforces
codehorses
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
#define MAX 500000
#define INF 0x3f3f3f3f

int n , trash;
vector<int> v[60];
string s , q;
int32_t main(){
	IOS;
	cin >> n >> trash;
	cin >> s;
	REP(i , 0 , s.size()) v[s[i] - 'a'].pb(i);
	REP(i , 0 , n){
		cin >> q;
		int ans = 0;
		REP(j , 0 , q.size()){
			int now = q[j] - 'a';
			if(v[now].size() == 0) ans += q.size();
			else {
				int pos = lower_bound(v[now].begin() , v[now].end() , j) - v[now].begin();
				int val = INF;
				if(pos != v[now].size())
					val = min(val , v[now][pos] - j);
				if(pos != 0)
					val = min(val , j - v[now][pos - 1]);
				ans += val;
			}
		}
		cout << ans << endl;
	}
    return 0;
}