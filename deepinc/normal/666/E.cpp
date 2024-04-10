#include<bits/stdc++.h>
using namespace std;
const int S=1.2e6,T=S*25;
int lst=1,pc=1,c[26][S],f[S],len[S],rt[S],rp[S],mx[T],lp[T];
int fir[S],l[S],to[S],ec,F[22][S],rc[T],lc[T],n,tp; char s[S];
void link(int a,int b){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;}
void up(int p){
	if(mx[rc[p]]>mx[lc[p]])mx[p]=mx[rc[p]],lp[p]=lp[rc[p]];
	else mx[p]=mx[lc[p]],lp[p]=lp[lc[p]];
}
#define md (L+R>>1)
void insert(int&p,int x,int L=1,int R=n){
	if(!p)p=++tp,mx[p]=0,lp[p]=L; if(L==R){mx[p]++;return;}
	if(x<=md)insert(lc[p],x,L,md); else insert(rc[p],x,md+1,R); up(p);
}
int merge(int a,int b,int L=1,int R=n){
	if(!a||!b)return a|b; if(L==R){int o=++tp;mx[o]=mx[a]+mx[b];lp[o]=L;return o;}
	int o=++tp; lc[o]=merge(lc[a],lc[b],L,md); rc[o]=merge(rc[a],rc[b],md+1,R);
	up(o); return o;
}
int Mx,Lp;
void ask(int p,int l,int r,int L=1,int R=n){
	if(l<=L&&R<=r){if(mx[p]>Mx)Mx=mx[p],Lp=lp[p];return;}
	if(l<=md)ask(lc[p],l,r,L,md); if(r>md)ask(rc[p],l,r,md+1,R);
}
void dfs(int p){
	F[0][p]=f[p]; for(int i=1;i<22;++i)F[i][p]=F[i-1][F[i-1][p]];
	for(int i=fir[p];i;i=l[i])dfs(to[i]),rt[p]=merge(rt[p],rt[to[i]]);
}
void extend(int C,int op){
	int p=lst,np,q,nq;
	if(lst=q=c[C][p]){
		if(len[q]==len[p]+1)return insert(rt[q],op);
		len[lst=nq=++pc]=len[p]+1; f[nq]=f[q]; f[q]=nq; insert(rt[nq],op);
		for(int i=0;i<26;++i)c[i][nq]=c[i][q];
		for(;c[C][p]==q;p=f[p])c[C][p]=nq;
	}else{
		len[np=lst=++pc]=len[p]+1; if(op>0)insert(rt[np],op);else rp[-op]=np;
		for(;p&&!c[C][p];p=f[p])c[C][p]=np;
		if(!p){f[np]=1;return;}
		if(len[q=c[C][p]]==len[p]+1){f[np]=q;return;}
		len[nq=++pc]=len[p]+1; f[nq]=f[q]; f[q]=f[np]=nq;
		for(int i=0;i<26;++i)c[i][nq]=c[i][q];
		for(;c[C][p]==q;p=f[p])c[C][p]=nq;
	}
}
int main(){
	mx[0]=-1; scanf("%s",s+1); for(int i=1;s[i];++i)extend(s[i]-'a',-i);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		lst=1; scanf("%s",s);
		for(int j=0;s[j];++j)extend(s[j]-'a',i);
	}
	for(int i=2;i<=pc;++i)link(f[i],i);
	dfs(1);
	int q;scanf("%d",&q);for(int _=1,l,r,pl,pr;_<=q;++_){
		scanf("%d%d%d%d",&pl,&pr,&l,&r); l=r-l+1;
		int p=rp[r]; for(int i=21;~i;--i)if(len[F[i][p]]>=l)p=F[i][p];
		Mx=0;ask(rt[p],pl,pr);if(Mx)printf("%d %d\n",Lp,Mx);else printf("%d %d\n",pl,0);
	}
}