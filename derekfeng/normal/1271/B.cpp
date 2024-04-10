#include <bits/stdc++.h>	
using namespace std;
int f[203];
int main(){
	int n;
	string s;cin>>n>>s;
	s="0"+s;
	if (n==1){
		cout<<"0";return 0;
	}
	for (int i=1;i<=n;i++){
		if(s[i]=='B') s[i]=1;
		else s[i]=0;
	}
	for (int now=0;now<2;now++){
		int ans=0;
		memset (f,0,sizeof(f));
		for (int i=1;i<=n-1;i++){
			if (now!=s[i]^f[i-1]){
				ans++;
				f[i]=1;
			}
		}
		if (f[n-1]^s[n]==now){
			cout<<ans<<"\n";
			for (int i=1;i<=n-1;i++)
				if (f[i]==1) cout<<i<<" ";
			return 0;
		}
	}
	puts("-1");
	return 0;
}