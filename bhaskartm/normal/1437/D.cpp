#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int level[200005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		level[1]=1;
		vector<int>v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			v.pb(x);
		}
		
		level[2]++;
		int ans=1;
		int la=v[1];
		int curr=1;
		
		for(int i=2; i<n; i++){
			if(level[curr]==0){
				la=0;
				curr++;
				i--;
				continue;
			}
			if(v[i]>la){
				la=v[i];
				level[curr+1]++;
				ans=max(ans, curr);
				continue;
			}
			else{
				level[curr]--;
				if(level[curr]==0){
					i--;
					la=0;
					curr++;
					
					continue;
				}
				level[curr+1]++;
				ans=max(ans, curr);
				la=v[i];
			}
		}
		cout<<ans<<endl;
		for(int i=1; i<=n+2; i++){
			level[i]=0;
		}
	}
	return 0;
}