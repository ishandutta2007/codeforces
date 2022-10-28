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
		string st;
		cin>>st;
		int la=0;
		int ans=0;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='0'){
				la=0;
			}
			else{
				if(la==1){
					ans++;
				}
				la=1;
			}
		}
		int ans2=0;
		int la2=1;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='1'){
				la2=1;
			}
			else{
				if(la2==0){
					ans2++;
				}
				la2=0;
			}
		}
		cout<<max(ans,ans2)<<endl;
	}
	return 0;
}