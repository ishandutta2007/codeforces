#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int l1, r1;
		cin>>l1>>r1;
		int l2, r2;
		cin>>l2>>r2;
		int inter=min(r1, r2)-max(l1, l2);
		int rwd=max(r1, r2)-min(l1, l2);
		if(inter>=0){
			int al=(inter);
			if(n*al>=k){
				cout<<0<<endl;
				continue;
			}
			int mor=(rwd-al)*n;
			if(rwd*n>=k){
				cout<<k-al*n<<endl;
				continue;
			}
			cout<<(rwd-al)*n+(k-rwd*n)*2<<endl;
			continue;
		}
		int inp=(-inter);
		
		if(k<=rwd){
			cout<<k+inp<<endl;
			continue;
		}
		if(inp>=rwd){
			cout<<inp+rwd+2*(k-rwd)<<endl;
			continue;
		}
		int rem=(k-rwd);
		int ans=inp+rwd;
		n--;
		int pt=0;
		while(1){
			pt++;
			if(rem==0){
				break;
			}
			if(n==0){
				ans+=2*rem;
				rem=0;
				break;
			}
			if(rem>=rwd ){
				
				rem-=rwd;
				ans+=(inp+rwd);
				n--;
				continue;
			}
			else{
				int mini=min(inp+rem, 2*rem);
				ans+=mini;
				rem=0;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}