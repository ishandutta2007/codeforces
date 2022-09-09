#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,j,p[200005],pc,v[200005],mi[200005],smi[200005],c[200005];
long long ans;
int main(){
	for(i=2;i<=200000;i++){
		if(!v[i]){
			p[v[i]=++pc]=i;
			smi[pc]=mi[pc]=0x3f3f3f3f;
		}
		rep(j,pc){
			if(i*p[j]>200000) break;
			v[i*p[j]]=-1;if(i%p[j]==0) break;
		}
	}
	scanf("%d",&n);
	rep(j,n){
		int x;scanf("%d",&x);
		rep(i,pc){
			if(1ll*p[i]*p[i]>x) break;
			int t=0;
			while(x%p[i]==0){
				x/=p[i];
				t++;
			}
			if(t){
				c[i]++;
				smi[i]=min(smi[i],t);
				if(smi[i]<mi[i]) swap(mi[i],smi[i]);
			}
		}
		if(x!=1){
			i=v[x];
			c[i]++;
			smi[i]=min(smi[i],1);
			if(smi[i]<mi[i]) swap(mi[i],smi[i]);
		}
	}
	ans=1;
	rep(i,pc){
		int t=(c[i]==n?smi[i]:(c[i]==n-1?mi[i]:0));
		while(t--) ans=ans*p[i];
	}
	cout<<ans<<endl;
	return 0;
}