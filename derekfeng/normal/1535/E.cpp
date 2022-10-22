#include<bits/stdc++.h>
using namespace std;
#define clr fflush(stdout)
int par[20][300004];
int n,a[300004],c[300004];
int bs(int x){
	for(int i=19;~i;i--)if(par[i][x]!=-1&&a[par[i][x]]>0)x=par[i][x];
	return x;
}
int main(){
	memset(par,-1,sizeof(par));
	int q;cin>>q>>a[0]>>c[0];
	while(q--){
		++n;
		clr;
		int op;cin>>op;
		if(op==1){
			clr;
			cin>>par[0][n]>>a[n]>>c[n];
			clr;
			for(int i=1;i<20&&par[i-1][n]!=-1;i++)par[i][n]=par[i-1][par[i-1][n]];
		}else{
			clr;
			int x,w;cin>>x>>w;
			clr;
			int ans=0;
			long long res=0;
			for(;w>0;){
				int y=bs(x);
				if(y==x&&a[x]==0)break;
				if(a[y]<=w){
					ans+=a[y],res+=(long long)c[y]*a[y],w-=a[y],a[y]=0;
				}else{
					ans+=w,res+=(long long)w*c[y],a[y]-=w,w=0;
				}
				if(w==0)break;
			}
			clr;
			cout<<ans<<" "<<res<<"\n";
			clr;
		}
	}
}