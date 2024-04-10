#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int o=2e5+10;
int T,n,K,h[o],cnt,s[o];map<int,long long> f[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
long long slv(int nw,int k){
	if(f[nw].find(k)!=f[nw].end()) return f[nw][k];
	long long res=k*1ll*s[nw];int sn=0;vector<long long> vec;
	for(int i=h[nw];i;i=e[i].p) ++sn;
	for(int i=h[nw];i;i=e[i].p) res+=slv(e[i].v,k/sn),vec.push_back(slv(e[i].v,(k+sn-1)/sn)-slv(e[i].v,k/sn));
	sort(vec.begin(),vec.end());
	if(sn) for(int i=vec.size(),j=k%sn;j--;res+=vec[--i]);
	return f[nw][k]=res;
}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",slv(1,K)),cnt=0){
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;++i) h[i]=0;
		for(int i=2,p;i<=n;++i) scanf("%d",&p),ad(p,i);
		for(int i=1;i<=n;++i) f[i].clear(),scanf("%d",&s[i]);
	}
	return 0;
}