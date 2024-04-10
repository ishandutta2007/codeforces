#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int o=3e5+10,inf=1e9;
int T,n,q,p[o],a[o],ls[o],rs[o],st[o],tp,rt,k,s[o],L,R;bool flg;set<int> S;set<int>::iterator iter;
struct cons{int l,r;}c[o];
int dfs(int nw,int r){
	int l=1;
	if(a[nw]>r) flg=1;
	if(a[nw]) r=min(r,a[nw]-1);
	if(ls[nw]) l=max(l,dfs(ls[nw],r));
	if(rs[nw]) l=max(l,dfs(rs[nw],r));
	if(a[nw]&&a[nw]<l) flg=1;
	if(a[nw]) l=max(l,a[nw]+1);
	else c[++k].l=l,c[k].r=r;
	return l;
}
inline bool Cmp(cons A,cons B){return A.l>B.l;}
inline bool cmp(cons A,cons B){return A.r<B.r;}
int main(){
	for(scanf("%d",&T);T--;tp=k=flg=0,S.clear()){
		scanf("%d%d",&n,&q);L=0;R=inf;
		for(int i=1;i<=n;++i) scanf("%d",&p[i]);
		for(int i=1;i<=n;rs[st[++tp]=i++]=0){
			for(st[tp+1]=0;tp&&p[st[tp]]<p[i];--tp);
			ls[rs[st[tp]]=i]=st[tp+1];
			if(!tp) rt=i;
		}
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		dfs(rt,inf);
		for(int i=1;i<k;++i) scanf("%d",&s[i]),S.insert(s[i]);
		sort(c+1,c+k+1,Cmp);
		for(int i=1;i<=k;++i)
			if((iter=S.upper_bound(c[i].r))==S.begin()||(*--iter)<c[i].l) flg|=!!L,L=c[i].l;
			else S.erase(iter);
		for(int i=1;i<k;++i) S.insert(s[i]);
		sort(c+1,c+k+1,cmp);
		for(int i=1;i<=k;++i)
			if((iter=S.lower_bound(c[i].l))==S.end()||(*iter)>c[i].r) flg|=(R<inf),R=c[i].r;
			else S.erase(iter);
		for(int d;q--;printf((L<=d&&d<=R&&!flg)?"YES\n":"NO\n")) scanf("%d",&d);
	}
	return 0;
}