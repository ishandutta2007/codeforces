#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
string s;
ll ans;
int p,f[200004];
int main(){
	cin>>t;
	while(t--){
		cin>>s;n=s.size();
		p=-1;ans=0;
		for(int i=0;i<n;i++){
			if(p==-1){
				if(s[i]=='?')f[i]=i-p;
				else f[i]=i-p;
			}else{
				if(s[i]=='?')f[i]=i-p+f[p];
				else{
					f[i]=i-p;
					if((s[i]!=s[p])^((i-p+1)&1))f[i]+=f[p];
				}
			}
			if(s[i]!='?')p=i;
			ans+=f[i];
		}
		cout<<ans<<"\n";
	}
}