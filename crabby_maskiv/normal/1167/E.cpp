#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N];
int mxp[N],mnp[N],pre[N],suf[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	memset(mnp,0x3f,sizeof(mnp));
	memset(suf,0x3f,sizeof(suf));
	for(i=1;i<=n;i++){
		cin>>a[i];
		mnp[a[i]]=min(mnp[a[i]],i);
		mxp[a[i]]=max(mxp[a[i]],i);
	}
	pre[1]=mxp[1];
	for(i=2;i<=m;i++){
		if(mnp[i]<pre[i-1]){
			while(i<=m) pre[i++]=-1;
			break;
		}
		pre[i]=max(pre[i-1],mxp[i]);
	}
	suf[m]=mnp[m];
	for(i=m-1;i;i--){
		if(mxp[i]>suf[i+1]){
			while(i) suf[i--]=-1;
			break;
		}
		suf[i]=min(suf[i+1],mnp[i]);
	}
	int pos=1;
	ll ans=0;
	while(suf[pos]==-1) pos++;
	for(i=1;i<=m;i++){
		if(pre[i-1]==-1) break;
		while(suf[pos]<pre[i-1]&&pos<=m) pos++;
		if(pos<=i) pos=i+1;
		ans+=m-pos+2;
	}
	cout<<ans;
	return 0;
}