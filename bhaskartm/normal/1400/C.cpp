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
		string st;
		cin>>st;
		int x;
		cin>>x;
		int n=st.size();
		int ans[n];
		for(int i=0; i<n; i++){
			ans[i]=1;
		}
		for(int i=0; i<st.size(); i++){
			if(st[i]=='1'){
				continue;
			}
			if(i-x>=0){
				ans[i-x]=0;
			}
			if(i+x<n){
				ans[i+x]=0;
			}
		}
		
		bool che=1;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='0'){
				continue;
			}
			bool val=0;
			if(i-x>=0 && ans[i-x]==1){
				val=1;
			}
			if(i+x<n && ans[i+x]==1){
				val=1;
			}
			if(val==0){
				che=0;
			}
		}
		if(che==0){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0; i<n; i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}