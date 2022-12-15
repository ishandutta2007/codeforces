#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
int lowbit(int x){return x&-x;}
const int N=500001,M=N;
int n,m;
int a[N+1],p[N+1],b[M+1];
int id[N+1];
struct bitree{
	int sum[N+1];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int x,int v){
		while(x<=n)sum[x]+=v,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
	int _sum(int l,int r){return Sum(r)-Sum(l-1);}
}bit;
int now[M+1];
int dp[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	n++;a[n]=n;
	for(int i=1;i<n;i++)scanf("%lld",p+i);
	cin>>m;
	for(int i=1;i<=m;i++)scanf("%lld",b+i),id[b[i]]=i;
	b[++m]=n;id[n]=m;// 
	bit.init();
	memset(now,0x3f,sizeof(now));
	now[0]=0;
	int ne=0;
	for(int i=1;i<=n;i++){
		if(id[a[i]]){
			if(now[id[a[i]]-1]<inf)dp[i]=now[id[a[i]]-1]+bit._sum(b[id[a[i]]-1]+1,n)+ne;
			else dp[i]=inf;
			if(p[i]>=0)bit.add(a[i],p[i]);
			else ne+=p[i];
			if(dp[i]<inf)now[id[a[i]]]=min(now[id[a[i]]],dp[i]-bit._sum(a[i]+1,n)-ne);
		}
		else{
			if(p[i]>=0)bit.add(a[i],p[i]);
			else ne+=p[i];
		}
	}
	if(dp[n]<inf)cout<<"YES\n"<<dp[n];
	else puts("NO"); 
	return 0;
}