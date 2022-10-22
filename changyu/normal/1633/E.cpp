#include<bits/stdc++.h>
const int M=303,N=53,X=1e8;
int n,m,q,p[N],s[M],t[M],tmp[M*3],cnt,k,b0[M*3];
long long b1[M*3],S;
struct edge{int u,v,c,p;}e[M];
int Find(int u){return p[u]==u?u:p[u]=Find(p[u]);}
inline bool Check(int x,int ps){
	int u,v;
	bool res=0;
	std::sort(e+1,e+1+m,[&](const edge&a,const edge&b){return std::abs(a.c-x)==std::abs(b.c-x)?a.p<b.p:std::abs(a.c-x)<std::abs(b.c-x);});
	for(u=1;u<=n;u++)p[u]=u;
	for(int i=1;i<=m;i++)if((u=Find(e[i].u))!=(v=Find(e[i].v))){
		p[u]=v;
		if(e[i].p==ps)res=1;
	}
	std::sort(e+1,e+1+m,[](const edge&a,const edge&b){return a.p<b.p;});
	return res;
}
signed main(){
	int u,v,c,d,P,A,B,C;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&u,&v,&c),e[i]=(edge){u,v,c,i};
	for(int i=1;i<=m;i++){
		int l,r,md;
		l=0,r=e[i].c+1;
		for(;l<r;)md=l+r  >>1,Check(md,i)?r=md:l=md+1;
		s[i]=l;
		l=e[i].c-1,r=X;
		for(;l<r;)md=l+r+1>>1,Check(md,i)?l=md:r=md-1;
		t[i]=r;
		if(s[i]>t[i])continue;
		tmp[++cnt]=s[i];
		tmp[++cnt]=e[i].c;
		tmp[++cnt]=t[i];
	}
	std::sort(tmp+1,tmp+1+cnt);
	for(int i=1;i<=cnt;i++)if(i==1||tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(int i=1;i<=m;i++){
		if(s[i]>t[i])continue;
		s[i]=std::lower_bound(tmp+1,tmp+1+k,s[i])-tmp;
		c=std::lower_bound(tmp+1,tmp+1+k,e[i].c)-tmp;
		t[i]=std::lower_bound(tmp+1,tmp+1+k,t[i])-tmp;
		b1[s[i]]+=e[i].c,b1[c]-=2*e[i].c,b1[t[i]+1]+=e[i].c;
		--b0[s[i]],b0[c]+=2,--b0[t[i]+1];
	}
	for(int i=1;i<=k;i++)b0[i]+=b0[i-1],b1[i]+=b1[i-1];
	scanf("%d%d%d%d%d",&P,&q,&A,&B,&C);
	for(int j=1;j<=q;j++){
		if(j<=P)scanf("%d",&c);
		else c=((long long)c*A+B)%C;
		d=std::upper_bound(tmp+1,tmp+1+k,c)-tmp-1;
		S^=(long long)b0[d]*c+b1[d];
	}
	printf("%lld\n",S);
	return 0;
}