/*input
abacaba
ubuduba
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
#define MAX 1000900
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int cnt[30] , sum = 0 , gi[MAX] , ni[MAX] , xx[MAX];
int solveinit(){
	gi[0] = ni[0] = ni[1] = 1;
	REP(i , 1 , MAX) gi[i] = gi[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 0 , MAX) xx[i] = ni[i];
	REP(i,  2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;
}
string a , b;
int solve(string &s){
	sum = s.size();
	REP(i , 0 , 26) cnt[i] = 0;
	REP(i , 0 , a.size()) cnt[a[i] - 'a'] ++;
	int res = gi[sum] , ans = 0;
	REP(i , 0 , 26) res = res * ni[cnt[i]] % mod; 
	// DBGG("res = " , res);
	REP(i , 0 , s.size()){
		res = res * xx[sum--] % mod;
		REP(j , 0 , s[i] - 'a'){
			if(cnt[j]){
				int tmp = res * cnt[j] % mod;
				ans = (ans + tmp) % mod;
			}
		}
		if(cnt[s[i] - 'a'] == 0) return ans;
		else res = res * cnt[s[i] - 'a'] % mod , cnt[s[i] - 'a'] --;
	}
	return ans;
}
int32_t main(){
	solveinit();
	cin >> a >> b;
	// DBGG("solve(b) = " , solve(b));
	// DBGG("solve(a) = " , solve(a));
	int ans = (solve(b) + mod - solve(a) + mod - 1) % mod;
	cout << ans << endl;
    return 0;
}