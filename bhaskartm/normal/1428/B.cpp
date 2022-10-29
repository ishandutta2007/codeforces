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
		char arr[n];
		bool c1=0;
		bool c2=0;
		bool c3=0;
		bool che[n];
		for(int i=0; i<n; i++){
			che[i]=0;
		}
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(arr[i]=='>'){
				c1=1;
			}
			if(arr[i]=='<'){
				c2=1;
			}
			if(arr[i]=='-'){
				che[i]=1;
				che[(i+1)%n]=1;
				c3=1;
			}
		}
		if(c1==0 || c2==0){
			cout<<n<<endl;
		}
		else{
			int ans=0;
			for(int i=0; i<n; i++){
				if(che[i]){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}