#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
#define mkp make_pair
#define fi first
#define se second
int n,m,K,C[15][15],fc[8],cnt[15],a[15],tot;
bool g[15][15];
int px[10],py[10],N;
unordered_set<ll>dp;
vector<pil>all;
void divset(int x){
	if(x==n){
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)cnt[a[i]]++;
		bool tmp=1;
		for(int i=0;i<tot&&tmp;i++)tmp&=(cnt[i]%2==0);
		if(tmp){
			ll state=0;
			for(int i=0;i<n;i++)state=state*6+a[i];
			all.push_back(mkp(tot,state));
		}
		return;
	}
	a[x]=tot++;
	divset(x+1);
	--tot;
	for(int i=0;i<tot;i++){
		a[x]=i;
		divset(x+1);
	}
}
bool f[70][7];
bool check(){
	memset(f,0,sizeof(f));
	for(int i=0;i<n/2;i++)if(g[px[i]][py[i]])f[(1<<i)][i]=1;
	for(int i=1;i<(1<<(n/2));i++)
		for(int j=0;j<n/2;j++)if(f[i][j])
			for(int k=0;k<n/2;k++)if(!((1<<k)&i))
				if((g[px[j]][px[k]]&&g[py[j]][py[k]])||(g[px[j]][py[k]]&&g[py[j]][px[k]]))
					f[i|(1<<k)][k]=1;
	bool ans=0;
	for(int i=0;i<n/2&&!ans;i++)ans|=f[(1<<(n/2))-1][i];
	return ans;
}
void dfsinit(int mask){
	if(mask==0){
		if(check()){
			for(int i=0;i<n/2;i++)a[px[i]]=a[py[i]]=i;
			ll state=0;
			for(int i=0;i<n;i++)state=state*6+a[i];
			dp.insert(state);
		}
		return;
	}
	int x=__builtin_ffs(mask)-1;
	px[N]=x,mask^=(1<<x);
	for(int y=0;y<n;y++)if((1<<y)&mask){
		py[N++]=y;
		dfsinit(mask^(1<<y));
		N--;
	}
}
ll ans;
int b[15];
void trans(ll mask,int x,int y){
	for(int i=n-1;~i;i--){
		a[i]=mask%6,mask/=6;
		if(a[i]==y)a[i]=x;
	}
	memset(b,-1,sizeof(b)),N=0;
	ll state=0;
	for(int i=0;i<n;i++){
		if(b[a[i]]<0)b[a[i]]=N++;
		state=state*6+b[a[i]];
	}
	dp.insert(state);
}
int main(){
	for(int i=0;i<15;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	fc[0]=1;for(int i=1;i<8;i++)fc[i]=fc[i-1]*i;
	scanf("%d%d%d",&n,&m,&K);
	divset(0),sort(all.begin(),all.end(),greater<pil>());
	while(m--){
		int u,v;scanf("%d%d",&u,&v);
		u--,v--,g[u][v]=g[v][u]=1;
	}
	dfsinit((1<<n)-1);
	for(auto x:all){
		ll msk=x.se;int v=x.fi;
		if(dp.find(msk)==dp.end())continue;
		if(v<=K)ans+=(ll)C[K][v]*fc[v];
		for(int i=0;i<v;i++)for(int j=i+1;j<v;j++)trans(msk,i,j);
	}
	printf("%I64d",ans);
}