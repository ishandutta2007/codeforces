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
		string s;
		cin>>s;
		int n=s.size();
		int pre[n+1];
		pre[0]=0;
		int num=0;
		for(int i=1; i<=n; i++){
			if(s[i-1]=='1'){
				pre[i]=pre[i-1]+1;
				num++;
			}
			else{
				pre[i]=pre[i-1];
			}
		}
		int ans=10000;
		ans=min(ans, num);
		ans=min(ans, n-num);
		
		for(int i=1; i<n; i++){
			int val=0;
			val+=i-pre[i];
			val+=num-pre[i];
			ans=min(ans, val);
		}
		
		for(int i=1; i<n; i++){
			int val=0;
			val+=pre[i];
			val+=(n-i)-(num-pre[i]);
			ans=min(ans, val);
		}
		cout<<ans<<endl;
	}
	return 0;
}