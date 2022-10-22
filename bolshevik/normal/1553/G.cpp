#include<cstdio>
#include<set>
#include<utility>
#include<vector>
using namespace std;
const int o=1e6+10;
int n,q,a[o],b[o],fa[o],d[o],fir[o];vector<int> vec[o];set<pair<int,int> > S; 
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[a[i]]=i,fa[i]=i;
	for(int i=2;i<o;++i) if(!d[i]) for(int j=i;j<o;j+=i) ++d[j];
	for(int i=2;i<o;++i) vec[i].reserve(d[i]);
	for(int i=2;i<o;++i) if(d[i]<2) for(int j=i;j<o;j+=i) vec[j].push_back(i);
	for(int i=2;i<o;++i) if(d[i]<2) for(int j=i,u,v;j<o;j+=i) if(b[j]){
		if(!fir[i]) fir[i]=b[j];
		else if((u=fr(fir[i]))^(v=fr(b[j]))) fa[u]=v;
	}
	for(int i=1;i<=n;++i) for(int j=0,sz=vec[a[i]+1].size(),t,u,v;j<sz;++j)
		if(fir[t=vec[a[i]+1][j]]) if((u=fr(i))^(v=fr(fir[t]))) S.insert(make_pair(u,v));
	for(int i=1;i<=n;++i) for(int j=1,sz=vec[a[i]+1].size(),t1,t2,u,v;j<sz;++j) if(fir[t1=vec[a[i]+1][j]])
		for(int k=0;k<j;++k) if(fir[t2=vec[a[i]+1][k]]) if((u=fr(fir[t1]))^(v=fr(fir[t2]))) S.insert(make_pair(u,v));
	for(int s,t;q--;){
		scanf("%d%d",&s,&t);s=fr(s);t=fr(t);
		if(s==t) printf("0\n");
		else if(S.find(make_pair(s,t))!=S.end()||S.find(make_pair(t,s))!=S.end()) printf("1\n");
		else printf("2\n");
	}
	return 0;
}