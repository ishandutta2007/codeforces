#include<bits/stdc++.h>
using namespace std;
int Tc,K,n;
string S,ans;
void solve(){
	cin>>S>>K,ans="",n=S.size();
	if(K==1)for(int i=0;i<=n;i++)ans+="1";
	else{
		ans="1";
		for(int i=0;i<n;i++)ans+="0";
	}
	int msk=0;
	for(int i=0;i<=n;i++){
		if(i>0)msk|=(1<<(S[i-1]-'0'));
		if(__builtin_popcount(msk)>K)break;
		if(i==n){
			ans=S;
			break;
		}
		for(int j=0;j<10;j++)if(j>S[i]-'0'){
			int nmsk=msk|(1<<j);
			if(__builtin_popcount(nmsk)>K)continue;
			if(__builtin_popcount(nmsk)<K){
				string nS=(i==0?"":S.substr(0,i));
				nS+=(char)(j+'0');
				for(int k=i+1;k<n;k++)nS+="0";
				ans=nS;
				break;
			}else{
				string nS=(i==0?"":S.substr(0,i));
				nS+=(char)(j+'0');
				int nc=__builtin_ffs(nmsk)-1;
				for(int k=i+1;k<n;k++)nS+=(char)(nc+'0');
				ans=nS;
				break;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(cin>>Tc;Tc--;solve());
}