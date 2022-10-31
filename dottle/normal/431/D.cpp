#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

int l=1,r=1e18,n,m,k,ans;
int f[65][65][2],nw;

int F(int k,int p,int l){
	if(p<0)return 0;
	if(k<0)
		return p==0;
	if(~f[k][p][l])return f[k][p][l];
	if((nw>>k&1)||l)
		return f[k][p][l]=F(k-1,p-1,l)+F(k-1,p,l|1);
	else return f[k][p][l]=F(k-1,p,l);
}

int calc(int x){
	memset(f,-1,sizeof(f));
	nw=x;
	return F(63,k,0);
}

bool chk(int x){
	return calc(2*x)-calc(x)>=m;
}

main(){
	ios::sync_with_stdio(false);
	cin>>m>>k;
	while(l<=r){
		int mid=(l+r)>>1; 
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
}