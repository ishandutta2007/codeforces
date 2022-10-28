#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;
int cnt[N];
vector<vector<int>>vec;
int ans[N]; 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; i++){
			cnt[i]=0;
		}
		vec.clear();
		vec.resize(m);
		int maxi=(m+1)/2;
		bool che=1;
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			for(int j=0; j<x; j++){
				int val;
				cin>>val;
				vec[i].pb(val);
			}
			if(x==1){
				cnt[vec[i][0]]++;
				ans[i]=vec[i][0];
				if(cnt[vec[i][0]]>maxi){
					che=0;
				}
			}
		}
		if(che==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=0; i<m; i++){
			if(vec[i].size()==1){
				continue;
			}
			if(cnt[vec[i][0]]+1<=maxi){
				ans[i]=vec[i][0];
				cnt[vec[i][0]]++;
			}
			else{
				ans[i]=vec[i][1];
				cnt[vec[i][1]]++;
			}
		}
		for(int i=0; i<m; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}