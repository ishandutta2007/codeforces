#include<bits/stdc++.h>
using namespace std;
int T,n,m,s,w,S,W,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>w>>S>>W;
		ans=0;
		if(S>W)swap(S,W),swap(s,w); 
		for(int i=0;i<=s;i++)if(i<=n/S){
			int nn=n,mm=m,ret;
			nn-=S*i;
			int ok=min(m/S,s-i);
			ret=i+ok;
			mm-=S*ok;
			ret+=min(w,nn/W+mm/W);
			ans=max(ans,ret);
		}
		cout<<ans<<"\n";
	}
}