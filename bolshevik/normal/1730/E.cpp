#include<cstdio>
#include<vector>
using namespace std;
const int o=1e6+10;
int T,n,a[o],st[o],tp,l1[o],r1[o],l2[o],r2[o],p[o];long long ans;vector<int> d[o],vec[o];
inline void upd(int x,int y){
	ans+=max(0,min(y,x)-max(l1[y],l2[x])+1)*1ll*max(0,min(r1[y],r2[x])-max(y,x)+1);
}
inline void Upd(int x,int y,int z){
	ans-=max(0,min(min(x,y),z)-max(max(l2[x],l1[y]),l2[z])+1)*1ll*max(0,min(min(r2[x],r1[y]),r2[z])-max(max(x,y),z)+1);
}
int main(){
	for(int i=1;i<o;++i) for(int j=i;j<o;j+=i) d[j].push_back(i);
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;l1[i]=st[tp]+1,st[++tp]=i++) for(;tp&&a[st[tp]]<a[i];r1[st[tp--]]=i-1);
		for(;tp;r1[st[tp--]]=n);
		for(int i=1;i<=n;l2[i]=st[tp]+1,st[++tp]=i++) for(;tp&&a[st[tp]]>=a[i];--tp);
		st[tp=0]=n+1;
		for(int i=n;i;r2[i]=st[tp]-1,st[++tp]=i--) for(;tp&&a[st[tp]]>=a[i];--tp);
		st[tp=0]=0;
		for(int i=1;i<=n;++i) vec[a[i]].push_back(i);
		for(int i=1;i<=n;++i) for(int j=d[a[i]].size()-1,v;j--;) if(!vec[v=d[a[i]][j]].empty()){
			for(;p[v]+1<vec[v].size()&&vec[v][p[v]+1]<i;++p[v]);
			upd(vec[v][p[v]],i);
			if(vec[v][p[v]]<i&&p[v]+1<vec[v].size()) upd(vec[v][p[v]+1],i),Upd(vec[v][p[v]],i,vec[v][p[v]+1]);
		}
		for(int i=1,j;i<=n;ans+=j*(j+1ll)/2,++i) for(j=1;i<n&&a[i]==a[i+1];++i) ++j;
		for(int i=1;i<=n;++i) vec[a[i]].clear(),p[a[i]]=0;
	}
	return 0;
}