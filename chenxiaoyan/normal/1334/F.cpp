/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=500001,M=N;
int n,m;
int a[N+1],p[N+1],b[M+1];
int id[N+1];
vector<int> pos[N+1];
int lwb[N+1];
int add[M+1];
int now[M+1];
int dp[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	n++;a[n]=n;
	for(int i=1;i<n;i++)scanf("%lld",p+i);
	cin>>m;
	for(int i=1;i<=m;i++)scanf("%lld",b+i),id[b[i]]=i;
	b[++m]=n;id[n]=m;
	for(int i=1;i<=n;i++)pos[a[i]].pb(i);
	for(int i=1,j=1;i<=n;i++){
		if(b[j]<i)j++;
		lwb[i]=j;
	}
	memset(now,0x3f,sizeof(now));
	now[0]=0;
	int ne=0;
	for(int i=1;i<=n;i++){
		if(id[a[i]]){
			if(now[id[a[i]]-1]<inf)dp[i]=now[id[a[i]]-1]+add[id[a[i]]]+ne;
			else dp[i]=inf;
			if(p[i]>=0)add[lwb[a[i]]]+=p[i];
			else ne+=p[i];
			if(dp[i]<inf)now[id[a[i]]]=min(now[id[a[i]]],dp[i]-ne);
//			printf("dp[%lld]=%lld\n",i,dp[i]);
		}
		else{
			if(p[i]>=0)add[lwb[a[i]]]+=p[i];
			else ne+=p[i];
		}
	}
	if(dp[n]<inf)cout<<"YES\n"<<dp[n];
	else puts("NO");
	return 0;
}