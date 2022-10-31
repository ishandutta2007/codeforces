
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e17;
 
void solve(){
	int n[3];
	for(int i=0;i<3;i++)	cin>>n[i];
	
	vector<int>a[3];
	int tot=0;	
	int sum[3]{};
	for(int i=0;i<3;i++){
		for(int k=0;k<n[i];k++){
			int x;cin>>x;
			a[i].push_back(x);
			tot+=x;
			sum[i]+=x;
		}
		sort(a[i].begin(), a[i].end());
	}
 
	// Finaly take idx
	int res=-INF;
	for(int idx=0;idx<3;idx++){
		int curr=0;
		for(int k=0;k<3;k++){
			if(k==idx)	continue;
			curr-=a[k][0];
		}
		// cout<<curr<<"\n";
		res=max(res, tot+2*curr);
		// cout<<tot-(2*sum[idx])<<"\n";
		res=max(res, tot-(2*sum[idx]));
	}
	cout<<res<<"\n";
}	
 
main(){
    solve();
}