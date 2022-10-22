#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[22][22],K;
int n,m;
ll ans;
int L,R,N,r,c;
ll f[1100000];
map<ll,int>mp[22];
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d%I64d",&n,&m,&K);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%I64d",&a[i][j]);
	N=n+m-2,L=N/2,R=N-L,r=n-1,c=m-1;
	if(N<=1){
		ll Z=a[1][1]^a[1][2]^a[2][1]^a[2][2];
		return puts(Z==K?"1":"0"),0;
	}
	for(int i=0;i<(1<<L);i++){
		int dow=__builtin_popcount(i),rig=L-i;
		if(dow>r||rig>c)continue;
		int x=1,y=1;
		ll s=a[1][1];
		for(int j=0;j<L;j++){
			if((1<<j)&i)x++;
			else y++;
			s^=a[x][y];
		}
		f[i]=s;
	}
	for(int i=0;i<(1<<R);i++){
		int dow=__builtin_popcount(i),rig=R-i;
		if(dow>r||rig>c)continue;
		int x=n,y=m;
		ll s=a[n][m];
		for(int j=R-1;j;j--){
			if((1<<j)&i)x--;
			else y--;
			s^=a[x][y];
		}
		mp[dow][s]++;
	}
	for(int i=0;i<(1<<L);i++)if(~f[i])
		ans+=mp[r-__builtin_popcount(i)][f[i]^K];
	printf("%I64d",ans);
}