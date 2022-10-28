#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int cnt[n+1];
		for(int i=0; i<=n; i++){
			cnt[i]=0;
		}
		int maxi=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			cnt[arr[i]]++;
			maxi=max(maxi, cnt[arr[i]]);
		}
		if(maxi>((n+1)/2)){
			cout<<-1<<endl;
			continue;
		}
		int las=0;
		vector<pair<int, int>>vec;
		for(int i=0; i<n-1; i++){
			if(arr[i]==arr[i+1]){
				vec.pb({las, i});
				las=i+1;
			}
		}
		vec.pb({las, n-1});
		if(vec.size()==1){
			cout<<0<<endl;
			continue;
		}
		int c2[n+1];
		for(int i=0; i<=n; i++){
			c2[i]=0;
		}
		for(int i=0; i<vec.size(); i++){
			if(arr[vec[i].f]==arr[vec[i].s]){
				c2[arr[vec[i].f]]++;
			}
		}
		int ma=0;
		int ind=-1;
		
		for(int i=1; i<=n; i++){
			if(c2[i]>ma){
				ind=i;
				ma=c2[i];
			}
		}
		
		int tot=0;
		for(int i=0; i<vec.size(); i++){
			if(arr[vec[i].f]!=ind && arr[vec[i].s]!=ind){
				tot++;
			}
		}
		ma-=tot;
		ma-=1;
		ma=max(ma, 0LL);
		cout<<vec.size()-1+ma<<endl;
		
	}
	return 0;
}