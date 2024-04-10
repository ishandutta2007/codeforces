#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second

map<int, vector<pair<int, int>>>ma;

main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		int val=max(x, y);
		ma[val].pb({x, -y});
	}
	for(auto it=ma.begin(); it!=ma.end(); it++){
		vector<pair<int, int>> v=it->second;
		sort(v.begin(), v.end());
		int val=it->first;
		ma[val]=v;
	}
	
	
	int dp[2];
	dp[0]=0;
	dp[1]=0;
	pair<int, int> l={0, 0};
	pair<int, int> r={0, 0};
	for(auto it=ma.begin(); it!=ma.end(); it++){
		vector<pair<int, int>> v=it->second;
		pair<int, int> le=v[0];
		pair<int, int> ri=v[v.size()-1];
		int val1=min(dp[0]+abs(le.f-l.f)+abs(le.s-l.s), dp[1]+abs(le.f-r.f)+abs(le.s-r.s));
		int val0=min(dp[0]+abs(ri.f-l.f)+abs(ri.s-l.s) , dp[1]+abs(ri.f-r.f)+abs(ri.s-r.s));
		
		val0+=(abs(ri.f-le.f)+abs(ri.s-le.s));
		val1+=(abs(ri.f-le.f)+abs(ri.s-le.s));
			
		dp[0]=val0;
		dp[1]=val1;
		
		l=le;
		r=ri;
	}
	cout<<min(dp[0], dp[1]);
	return 0;
}