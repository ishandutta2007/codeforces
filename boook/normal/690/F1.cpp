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
#define int long long
#define MAX 10090
#define INF 0x3f3f3f3f

int n;
vector<int> v[MAX];
int32_t main(){
	cin >> n;
	REP(i , 1 , n){
		int q , w;
		cin >> q >> w;
		v[q].pb(w);
		v[w].pb(q);
	}
	int ans = 0;
	REP(i , 1 , n + 1){
		int siz = v[i].size();
		ans += (siz) * (siz - 1) / 2;
	}
	cout << ans << endl;
    return 0;
}