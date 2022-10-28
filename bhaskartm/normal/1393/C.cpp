#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'
int cnt[100005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	int iter=0;
	while(t--){
		iter++;
		int n;
		cin>>n;
		int maxi=0;
		int fre=0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			cnt[x]++;
			if(cnt[x]>maxi){
				fre=1;
				maxi=cnt[x];
				continue;
			}
			if(cnt[x]==maxi){
				fre++;
				continue;
			}
		}
		
	
			cout<<((n-fre)/(maxi-1))-1<<endl;
		
		
		for(int i=1; i<=n; i++){
			cnt[i]=0;
		}
	}
	
	return 0;
}