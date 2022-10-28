#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, x, m;
		cin>>n>>x>>m;
		int curl=x;
		int curr=x;
		
		for(int i=0; i<m; i++){
			int l, r;
			cin>>l>>r;
			if(l>curr){
				continue;
			}
			if(r<curl){
				continue;
			}
			if(l<=curr){
				curr=max(r, curr);
			}
			if(r>=curl){
				curl=min(l, curl);
			}
		}
		cout<<curr-curl+1<<endl;
	}
	return 0;
}