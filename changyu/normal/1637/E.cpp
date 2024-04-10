#include<bits/stdc++.h>
#define int long long
///clear
const int N=3e5+3;
int n,m,a[N],tmp[N],k,b[N],ans;
bool vis[N],fl[N];
std::vector<int>c,h[N],g[N];
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),tmp[i]=a[i];
	std::sort(tmp+1,tmp+1+n);
	k=0;
	for(int i=1;i<=n;i++)if(i==1||tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	std::fill(b+1,b+1+k,0);
	for(int i=1;i<=n;i++){
		a[i]=std::lower_bound(tmp+1,tmp+1+k,a[i])-tmp;
		++b[a[i]];
	}
	std::fill(vis+1,vis+1+k,0);
	for(int i=1;i<=n;i++)if(!vis[a[i]])h[b[a[i]]].push_back(a[i]),vis[a[i]]=1;
	for(int i=1;i<=n;i++)if(h[i].size()){
		c.push_back(i);
		std::sort(h[i].begin(),h[i].end(),[](const int&a,const int&b){return a>b;});
	}
	for(int x,y;m--;){
		scanf("%lld%lld",&x,&y);
		x=std::lower_bound(tmp+1,tmp+1+k,x)-tmp;
		y=std::lower_bound(tmp+1,tmp+1+k,y)-tmp;
		g[x].push_back(y),g[y].push_back(x);
	}
	std::fill(vis+1,vis+1+k,0);
	for(int i=1;i<=n;i++)if(!vis[a[i]]){
		for(int j:g[a[i]])fl[j]=1;
		fl[a[i]]=1;
		for(int j:c)for(int k:h[j])if(/*printf("%d %d %d\n",i,j,k),*/!fl[k]){
			ans=std::max(ans,(tmp[k]+tmp[a[i]])*(j+b[a[i]]));//,printf("%lld\n",(tmp[k]+tmp[a[i]])*(j+b[a[i]]));
			break;
		}
		for(int j:g[a[i]])fl[j]=0;
		fl[a[i]]=0;
		vis[a[i]]=1;
	}
	for(int i=1;i<=k;i++)g[i].clear();
	for(int i=1;i<=n;i++)h[i].clear();
	c.clear();
	printf("%lld\n",ans);
	}return 0;
}