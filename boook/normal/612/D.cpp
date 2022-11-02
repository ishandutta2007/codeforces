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
#define MAX 1000900
#define INF 1000000000000000LL

int n , k;
vector<PII> v;
vector<PII> ans;
int32_t main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1){
		int q , w;
		cin >> q >> w;
		v.pb(mp(q , 1));
		v.pb(mp(w , 2));
	}
	sort(ALL(v));
	int num = 0;
	REP(i , 0 , v.size()){
		if(num >= k){
			int l = v[i - 1].A , r = v[i].A;
			if(l <= r) ans.pb(mp(l , r));
		}
		num += (v[i].B == 1 ? 1 : -1);
	}

	int po = 0;
	while(po + 1 < ans.size()){
		int nxt = po + 1;
		while(nxt < ans.size() && ans[po].B == ans[nxt].A){
			ans[po].B = ans[nxt].B;
			ans[nxt] = mp(INF , INF);
			nxt ++;
		}
		po = nxt;
	}
	int sum = 0;
	REP(i , 0 , ans.size())
		if(ans[i] != mp(INF , INF)) sum ++;
	cout << sum << endl;
	REP(i , 0 , ans.size()){
		if(ans[i] != mp(INF , INF))
			cout << ans[i].A << " " << ans[i].B << endl;
	}
    return 0;
}