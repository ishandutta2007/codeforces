#include<cstdio>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
const int o=1e5+10;
int T,n,a[o],b[o],p[o],ans;vector<int> e[o],d[o];bitset<o> usd;
bool Hungary(int x){
	if(usd[x]) return false;
	usd.set(x);
	for(int i=e[x].size(),j;i--;) if(!p[j=e[x][i]]||Hungary(p[j])) return p[j]=x;
	return false;
}
int main(){
	for(int i=1;i<o;++i) for(int j=i;j<o;j+=i) d[j].push_back(i);
	for(scanf("%d",&T);T--;printf("%d\n",ans-n),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[a[i]]=i;
		for(int i=1;i<=2*n;p[i++]=0) e[i].clear();
		for(int i=1;i<=n;++i) e[i].push_back(i+n);
		for(int i=1;i<=n;++i) for(int j=d[a[i]].size()-1,v;j--;)
			if(b[v=d[a[i]][j]]<=n&&a[b[v]]==v) e[i].push_back(b[v]),e[i+n].push_back(b[v]+n);
		for(int i=1;i<=2*n;ans+=Hungary(i++)) usd.reset();
	}
	return 0;
}