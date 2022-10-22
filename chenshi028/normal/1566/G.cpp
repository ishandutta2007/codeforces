#include<cstdio>
#include<set>
#include<map>
#include<utility>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline long long Min(long long a,long long b){return a<b?a:b;}
const int o=1e5+10;const long long inf=1e18;
int n,m,asd;set<pair<int,int> > e[o];set<pair<int,pair<int,int> > >g;map<pair<int,int>,int> mp;
set<pair<int,int> >::iterator iter;pair<int,pair<int,int> > tmp;multiset<long long> ms;
#define z (*iter)
inline pair<int,int> pr(int fi,int se){if(fi>se) return make_pair(se,fi);return make_pair(fi,se);}
inline void er(int u){
	int cnt=1;long long sm=0;
	for(iter=e[u].begin();cnt<4&&iter!=e[u].end();++iter,++cnt) sm+=z.first;
	if(cnt>3) ms.erase(sm);
}
inline void upd(int u){
	int cnt=1;long long sm=0;
	for(iter=e[u].begin();cnt<4&&iter!=e[u].end();++iter,++cnt) sm+=z.first;
	if(cnt>3) ms.insert(sm);
}
inline bool jy(int u,int v){
	int cnt=1;
	for(set<pair<int,int> >::iterator it=e[u].begin();cnt<4&&it!=e[u].end();++it,++cnt) if((*it).second==v) return true;
	return false;
}
inline void link(int u,int v,int w){
	er(u);er(v);
	e[u].insert(make_pair(w,v));e[v].insert(make_pair(w,u));mp[make_pair(u,v)]=w;
	upd(u);upd(v);
	bool b1=jy(u,v),b2=jy(v,u);int cnt1,cnt2;
	if(b1&&b2) g.insert(make_pair(w,make_pair(u,v)));
	if(b1){
		for(iter=e[u].begin(),cnt1=1;cnt1<4&&iter!=e[u].end();++iter,++cnt1);
		if(iter!=e[u].end()) g.erase(make_pair(z.first,pr(u,z.second)));
	}
	if(b2){
		for(iter=e[v].begin(),cnt2=1;cnt2<4&&iter!=e[v].end();++iter,++cnt2);
		if(iter!=e[v].end()) g.erase(make_pair(z.first,pr(v,z.second)));
	}
}
inline void cut(int u,int v,int w){
	er(u);er(v);
	bool b1=jy(u,v),b2=jy(v,u);int cnt1,cnt2;
	e[u].erase(make_pair(w,v));e[v].erase(make_pair(w,u));
	upd(u);upd(v);
	if(b1&&b2) g.erase(make_pair(w,make_pair(u,v)));
	if(b1){
		for(iter=e[u].begin(),cnt1=1;cnt1<3&&iter!=e[u].end();++iter,++cnt1);
		if(iter!=e[u].end()) if(jy(z.second,u)) g.insert(make_pair(z.first,pr(u,z.second)));
	}
	if(b2){
		for(iter=e[v].begin(),cnt2=1;cnt2<3&&iter!=e[v].end();++iter,++cnt2);
		if(iter!=e[v].end()) if(jy(z.second,v)) g.insert(make_pair(z.first,pr(v,z.second)));
	}
}
inline bool chk(int nu,int nv,int bu,int bv){return nu-bu&&nu-bv&&nv-bu&&nv-bv;}
inline void getans(){
	tmp=*g.begin();long long ans=*ms.begin();int a=tmp.second.first,b=tmp.second.second,cnt=1;
	for(set<pair<int,pair<int,int> > >::iterator iter_=g.begin();cnt<10&&iter_!=g.end();++iter_,++cnt)
		if(chk((*iter_).second.first,(*iter_).second.second,a,b)){ans=Min(ans,(*iter_).first+tmp.first);break;}
	int cnt1=1,cnt2=1;set<pair<int,int> >::iterator $;
	for(iter=e[a].begin();cnt1<5&&iter!=e[a].end();++iter,++cnt1)
		for($=e[b].begin(),cnt2=1;cnt2<5&&$!=e[b].end();++$,++cnt2)
			if(chk(a,z.second,b,(*$).second)) ans=Min(ans,z.first+(*$).first);
	printf("%lld\n",ans);
}
int main(){
	read(n);read(m);ms.insert(inf);
	for(int i=1,j,k,$;i<=m;++i){
		read(j);read(k);
		if(j>k) $=j,j=k,k=$;
		read($);link(j,k,$);
	}
	getans();
	read(m);
	for(int i=1,opt,j,k,$;i<=m;getans(),asd=++i){
		read(opt);read(j);read(k);
		if(j>k) $=j,j=k,k=$;
		if(opt) read($),link(j,k,$);
		else cut(j,k,mp[make_pair(j,k)]);
	}
	return 0;
}