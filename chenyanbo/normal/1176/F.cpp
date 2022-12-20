#include<bits/stdc++.h>
using namespace std;
#define N 210005
long long cc[N],f[10],g[10],ma,n,h,k,s1,s2,s3,c,d,S1[N],S2[N],S3[N];
void dfs(long long tot, long long to,long long da)
{
	if(to>3)return;
	f[(tot+h)%10]=max(f[(tot+h)%10],g[h]+da);
	if(to==3)return;
	long long dd;
	if((tot+h+1)%10 == 0)dd=2;else dd=1;
	for(int i=s1;i>=max(1ll,s1-2);--i)if(!cc[i]){
		cc[i]=1;
		dfs(tot+1,to+1,da+dd*S1[i]);
		cc[i]=0;
	}
	if(s2)dfs(tot+1,to+2,da+dd*S2[s2]);
	if(s3)dfs(tot+1,to+3,da+dd*S3[s3]);
}

int main()
{
	cin>>n;
	for(int i=1;i<=9;++i)f[i]=-1;
	for(int i=1;i<=n;++i){
		cin>>k;s1=0;s2=0;s3=0;
		for(int i=1;i<=k;++i){
			cin>>c>>d;
			if(c==1)S1[++s1]=d;
			if(c==2)S2[++s2]=d;
			if(c==3)S3[++s3]=d;
		}
		sort(S1+1,S1+s1+1);
		sort(S2+1,S2+s2+1);
		sort(S3+1,S3+s3+1);
		for(int i=0;i<=9;++i)g[i]=f[i];
		for(int i=0;i<=9;++i)f[i]=-1;
		for(h=0;h<=9;++h)if(g[h]>=0)dfs(0,0,0);
	}
	ma=0;for(int i=0;i<=9;++i)ma=max(ma,f[i]);
	cout<<ma;
}