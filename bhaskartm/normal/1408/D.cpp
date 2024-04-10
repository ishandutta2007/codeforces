#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double
int maxi[1000006];
int suf[1000006];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	vector<pair<int, int>>v1;
	vector<pair<int, int>>v2;
	for(int i=0; i<n; i++){
		int x, y;
		
		cin>>x>>y;
		v1.pb({x, y});
	}
	for(int i=0; i<m; i++){
		int x, y;
		
		cin>>x>>y;
		v2.pb({x, y});
	}
	for(int i=0; i<n; i++){
		int x1=v1[i].f;
		int x2=v1[i].s;
		for(int j=0; j<m; j++){
			int xx1=v2[j].f;
			int xx2=v2[j].s;
			if(x1>xx1 || x2>xx2){
				continue;
			}
			maxi[(xx1-x1+1)]=max(maxi[xx1-x1+1], xx2-x2+1);
		}
	}
	suf[1000005]=0;
	for(int i=1000004; i>=0; i--){
		suf[i]=max(suf[i+1], maxi[i]);
	}
	int ans=1e18;
	for(int i=0; i<=1000002; i++){
		ans=min(ans, i+suf[i+1]);
	}
	cout<<ans;
	return 0;
}