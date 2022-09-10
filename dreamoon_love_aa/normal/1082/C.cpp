#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define pi pair<int,int>
#define pb emplace_back
#define SZ(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define REP(i, j, k) for(int i = j; i < k; ++i)
#define debug(a) cout << #a << " = " << a << endl;
using namespace std;
int n, m;
map<int,vector<int> > s;
signed main()
{IOS
	cin >> n >> m;
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		s[a].pb(b);
	}
	for(auto &i:s) sort(all(i.second), [](int a, int b){
		return a > b;
	});
	for(auto &i:s) REP(j, 1, SZ(i.second)) i.second[j] += i.second[j - 1];
	int ans = 0, len = 0;
	for(auto i:s) len = max(len, SZ(i.second));
	vector<int> v;
	REP(p, 0, len)
	{
		int tot = 0;
		v.clear();
		for(auto& i:s) 
		{
			if(SZ(i.second) > p && i.second[p] > 0) tot += i.second[p];
			else v.pb(i.first);
		}
		for(auto i:v) s.erase(i);
		ans = max(ans, tot);
	}
	cout << ans;
}