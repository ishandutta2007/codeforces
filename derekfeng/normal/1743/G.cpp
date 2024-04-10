#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int N=3e6;
int tc,dp[33],as,bs;
ll nas,nbs;
int f[33],g[33],sz;
int nf[33],ng[33],nsz;
bitset<3000003>bs0,bs1;
void tran(bool c){
	nas=0,nbs=0,nsz=0;
	if(!c)nbs=as;
	else nf[nsz=1]=1,ng[1]=as;
	nas+=bs,nbs+=bs;
	for(int i=1;i<=sz;i++){
		int pos=(bs0[f[i]+1]^c)?0:f[i]+1;
		if(!bs1[pos])nas+=g[i];
		if(!pos)nbs+=g[i];
		if(pos)nf[++nsz]=pos,ng[nsz]=g[i];
	}
	as=nas%M,bs=nbs%M,sz=nsz;
	memcpy(f,nf,(sz+1)<<2);
	memcpy(g,ng,(sz+1)<<2);
}
char s[1004];
int main(){
	dp[0]=dp[1]=1,bs1.set(1);
	for(int i=2;i<32;i++)dp[i]=dp[i-1]+dp[i-2],bs1.set(dp[i]);
	bs0.set(1);
	for(int t=2;t<32;t++)
		for(int i=dp[t]+1;i<=min(N,dp[t]+dp[t-1]);i++)
			bs0[i]=bs0[i-dp[t]];
	int tc;scanf("%d",&tc);as=1;
	while(tc--){
		scanf("%s",s);int n=strlen(s);
		for(int i=0;i<n;i++)tran(s[i]-'0');
		printf("%d\n",as);
	}
}