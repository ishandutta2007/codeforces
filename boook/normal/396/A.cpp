/*input
2
5 7
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
#define MAX 100000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , mm[MAX] , ni[MAX];
map<int , int> cc;
int C(int a , int b){
	return mm[a] * ni[b] % mod * ni[a - b] % mod;
}
int32_t main(){
	mm[0] = ni[0] = ni[1] = 1;
	REP(i , 1 , MAX) mm[i] = mm[i - 1] * i % mod;
	REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
	REP(i , 2 , MAX) ni[i] = ni[i] * ni[i - 1] % mod;

	cin >> n;
	REP(i , 1 , n + 1){
		int in; cin >> in;
		REP(j , 2 , in + 1){
			if(j * j > in) break;
			while(in % j == 0){
				cc[j] ++;
				in /= j;
			}
		}
		if(in != 1) cc[in] ++;
	}
	int ans = 1;
	for(auto to : cc){
		ans = (ans * C(n + to.B - 1 , n - 1)) % mod;
	}
	cout << ans << endl;
    return 0;
}