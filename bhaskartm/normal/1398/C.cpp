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
		string s;
		cin>>s;
		int pre[s.size()+1];
		pre[0]=0;
		for(int i=1; i<=s.size(); i++){
			pre[i]=pre[i-1]+(s[i-1]-'0');
		}
		for(int i=0; i<=s.size(); i++){
			pre[i]=pre[i]-i;
		}
		map<int, int>cnt;
		cnt[0]=1;
		int ans=0;
		for(int i=1; i<=s.size(); i++){
			ans+=cnt[pre[i]];
			cnt[pre[i]]++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}