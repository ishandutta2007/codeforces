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
#define MAX 200500
#define INF 1000000000000000LL

int n , x[MAX] , ans;
string s[MAX];
int32_t main(){
    IOS;
    cin >> n;
    s[0] = s[n + 1] = "P";
    x[0] = -INF , x[n + 1] = INF;
    REP(i , 1 , n + 1) cin >> x[i] >> s[i];

    vector<int> p;
    REP(i , 0 , n + 2) if(s[i] == "P") p.pb(i);
    REP(id , 1 , p.size()){
    	int pre = p[id - 1] , now = p[id];

    		vector<int> b , r;
    		REP(i , pre , now + 1) if(s[i] != "R") b.pb(i);
    		REP(i , pre , now + 1) if(s[i] != "B") r.pb(i);
			int v1 = 0 , v2 = x[now] - x[pre];
    			v1 += x[now] - x[pre];
    			v1 += x[now] - x[pre];
    			// DB4("pre = " , pre , "now = " , now);
    			// for(auto to : b) cout << to << " ";cout << endl;
    			// for(auto to : r) cout << to << " ";cout << endl;
    			if(now == n + 1) v1 -= x[now] - x[b[b.size() - 2]];
    			if(pre == 0)     v1 -= x[b[1]] - x[pre];
    			if(now == n + 1) v1 -= x[now] - x[r[r.size() - 2]];
    			if(pre == 0)     v1 -= x[r[1]] - x[pre];
    			if(b.size() == 2 && pre == 0 && now == n + 1) v1 += x[now] - x[pre];
    			if(r.size() == 2 && pre == 0 && now == n + 1) v1 += x[now] - x[pre];
    			// DB4("v1 = " , v1 , "v2 = " , v2);
    			int sum = x[now] - x[pre] , sml;
    			sml = sum;
    			REP(i , 1 , b.size()) sml = min(sml , sum - (x[b[i]] - x[b[i - 1]]));
    			v2 += sml;
    			sml = sum;
    			REP(i , 1 , r.size()) sml = min(sml , sum - (x[r[i]] - x[r[i - 1]]));
    			v2 += sml;
    		ans += min(v1 , v2);
    	// DBGG("ans = " , ans);
    }
    cout << ans << endl;
    return 0;
}