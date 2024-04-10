#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int o=1e5+10;
int T,n,k,a[o],b[o],c,diff,mx,z;bool vis[o];map<int,int> mp;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",diff-mx),c=z=0,mp.clear()){
		scanf("%d%d",&n,&k);
		for(int i=0;i<=n;++i) vis[i]=0;
		for(int i=diff=1;i<=n;++i) scanf("%d",&a[i]),++mp[a[i]],vis[min(a[i],n)]=1;
		sort(a+1,a+n+1);
		for(int i=2;i<=n;++i) diff+=(a[i]!=a[i-1]);
		for(mx=0;vis[mx];++mx);
		for(;k--&&mx<n;++z) for(++mx,++diff;mx<n&&vis[mx];++mx);
		if(mx==n){diff=n;continue;}
		for(map<int,int>::iterator iter=mp.begin();iter!=mp.end();++iter) if((*iter).first>mx) b[++c]=(*iter).second;
		sort(b+1,b+c+1);
		for(int i=1;i<=c;++i) if((b[i]+=b[i-1])>z) break;else --diff;
	}
	return 0;
}