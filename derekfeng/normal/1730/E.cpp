#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+4;
int n,a[N],L[N],R[N];
int sta[N],SZ,it[N+N];ll ans;
int RD[N],LA[N],LB[N];
vector<int>fc[N+N],vec[N+N];
void sol(){
	for(int i=1;i<N+N;i++)
		if(!vec[i].empty())vec[i].clear();
	scanf("%d",&n),ans=0;
	for(int i=1,cnt=0;i<=n;i++){
		scanf("%d",&a[i]);
		cnt++;if(a[i]!=a[i-1])cnt=1;
		ans+=cnt,vec[a[i]].push_back(i);
	}
	SZ=0;sta[0]=0;
	for(int i=1;i<=n;i++){
		while(SZ&&a[sta[SZ]]<a[i])SZ--;
		L[i]=sta[SZ]+1,sta[++SZ]=i;
	}
	SZ=0;sta[0]=n+1;
	for(int i=n;i;i--){
		while(SZ&&a[sta[SZ]]<=a[i])SZ--;
		R[i]=sta[SZ]-1,sta[++SZ]=i;
	}
	SZ=0;sta[0]=n+1;
	for(int i=n;i;i--){
		while(SZ&&a[sta[SZ]]>=a[i])SZ--;
		RD[i]=sta[SZ]-1,sta[++SZ]=i;
	}
	SZ=0;sta[0]=0;
	for(int i=1;i<=n;i++){
		while(SZ&&a[sta[SZ]]>=a[i])SZ--;
		LA[i]=sta[SZ]+1,sta[++SZ]=i;
	}
	SZ=0;sta[0]=0;
	for(int i=1;i<=n;i++){
		while(SZ&&a[sta[SZ]]>a[i])SZ--;
		LB[i]=sta[SZ]+1,sta[++SZ]=i;
	}
	memset(it,-1,sizeof(it));
	for(int i=1;i<=n;i++){
		for(auto x:fc[a[i]]){
			while(it[x]+1<vec[x].size()&&vec[x][it[x]+1]<i)it[x]++;
			if(~it[x]){
				int pos=vec[x][it[x]];
				int lb=max(L[i],LA[pos]);
				int ub=min(R[i],RD[pos]);
				if(lb<=pos&&i<=ub)ans+=(ll)(pos-lb+1)*(ub-i+1);
			}
			if(it[x]+1<vec[x].size()){
				int pos=vec[x][it[x]+1];
				int lb=max(L[i],LB[pos]);
				int ub=min(R[i],RD[pos]);
				if(lb<=i&&pos<=ub)ans+=(ll)(i-lb+1)*(ub-pos+1);
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	for(int i=1;i<N+N;i++)
		for(int j=i+i;j<N+N;j+=i)
			fc[j].push_back(i);
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}