#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int pre[s.size()];
		if(s[0]=='+'){
			pre[0]=1;
		}
		else{
			pre[0]=-1;
		}
		int mini=pre[0];
		
		for(int i=1; i<s.size(); i++){
			if(s[i]=='+'){
				pre[i]=1+pre[i-1];
			}
			else{
				pre[i]=pre[i-1]-1;
			}
			mini=min(mini, pre[i]);
		}
		if(mini>=0){
			cout<<s.size()<<endl;
			continue;
		}
		int pos[s.size()+1];
		for(int i=0; i<=s.size(); i++){
			pos[i]=0;
		}
		for(int i=s.size()-1; i>=0; i--){
			if(pre[i]>=0){
				continue;
			}
			pos[(-pre[i])]=i;
		}
		int ans=0;
		for(int i=0; i<(-mini); i++){
			int po=pos[i+1];
			ans+=(1+po);
		}
		ans+=s.size();
		cout<<ans<<endl;
	}
	return 0;
}