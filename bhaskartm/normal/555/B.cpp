#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second

main() {
	int n, m;
	cin>>n>>m;
	pair<int, int>arr[n];
	for(int i=0; i<n; i++){
		int l,r;
		cin>>l>>r;
		arr[i]={l, r};
	}
	vector<pair<pair<int, int>, int>>v;
	for(int i=0; i<n-1; i++){
		int lo=arr[i+1].f-arr[i].s;
		int hi=arr[i+1].s-arr[i].f;
		v.pb({{lo, hi}, i});
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>>br;
	for(int i=1; i<=m; i++){
		int x;
		cin>>x;
		br.pb({x, i});
	}
	sort(br.begin(), br.end());
	int ans[n-1];
	for(int i=0; i<n-1; i++){
		ans[i]=-1;
	}
	int pointer=-1;
	set<pair<int, int>>s2;
	for(int i=0; i<br.size(); i++){
		int l=br[i].f;
		while(pointer<n-1 && v[pointer+1].f.f<=l){
			s2.insert({v[pointer+1].f.s, v[pointer+1].s});
			pointer++;
		}
		auto it=s2.lower_bound({l, -1});
		if(it==s2.end()){
			continue;
		}
		ans[(*it).s]=br[i].s;
		s2.erase((*it));
	}
	for(int i=0; i<n-1; i++){
		if(ans[i]==-1){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0; i<n-1; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}