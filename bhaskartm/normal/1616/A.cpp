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
		int cnt[105];
		for(int i=0; i<105; i++){
			cnt[i]=0;
		}
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			x=abs(x);
			cnt[x]++;
		}
		int ans=0;
		for(int i=0; i<=100; i++){
			if(i==0){
				if(cnt[i]>0){
					ans++;
				}
			}
			else{
				if(cnt[i]==1){
					ans++;
				}
				else if(cnt[i]!=0){
					ans+=2;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}