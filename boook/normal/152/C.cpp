/*input
4 5
ABABA
BCGDG
AAAAA
YABSA
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
#define MAX 1000
#define INF 0x3f3f3f3f
#define mod 1000000007LL


int n , m;
string s;
set<char> cc[MAX];
int32_t main(){
	IOS , cin >> n >> m;
	REP(i , 0 , n){
		cin >> s;
		REP(j , 0 , m) cc[j].insert(s[j]);
	}
	int ans = 1;
	REP(i , 0 , m){
		ans = (ans * cc[i].size()) % mod;
	}
	cout << ans << endl;
    return 0;
}