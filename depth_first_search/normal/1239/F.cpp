#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
int n,m,ee,x[N+5],y[N+5],s[N+5],q[N+5],lst[N+5],lnk[N+5],deg[N+5],vis[N+5],fa[N+5],tag[N+5];
struct edge {int to,nxt;}e[2*N+5];
struct data {int v;I bool operator < (Con data& o) Con {return fa[v]<fa[o.v];}}p[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void writes(Con string& x) {for(RI i=0,y=x.length();i^y;++i) pc(x[i]);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
I int getfa(CI x) {return fa[x]^x?fa[x]=getfa(fa[x]):x;}
I void FindLine(CI x)//1
{
	RI i,k,H=1,T=0;vis[q[++T]=x]=1;W(H<=T)
	{
		if(deg[k=q[H++]]%3==1&&k^x) break;
		for(i=lnk[k];i;i=e[i].nxt) !vis[e[i].to]&&(lst[q[++T]=e[i].to]=k,vis[e[i].to]=1);
	}W(s[k]=1,k^x) k=lst[k];
}
I void FindOnTree(CI x,CI st)//x 
{
	RI i,k,H=1,T=0;vis[q[++T]=x]=1;W(H<=T)
	{
		if(tag[k=q[H++]]&&k^x) break;
		for(i=lnk[k];i;i=e[i].nxt) !vis[e[i].to]&&(lst[q[++T]=e[i].to]=k,vis[e[i].to]=1);
	}W(s[k]=1,k^x) k=lst[k];
}
I bool FillCircle(CI x,CI st,CI f=1)//st,f
{
	if(f>2) for(RI i=lnk[x];i;i=e[i].nxt) if(e[i].to==st) return s[x]=1;// 
	vis[x]=2;for(RI i=lnk[x];i;i=e[i].nxt) if(vis[e[i].to]==1)
		if(FillCircle(e[i].to,st,f+1)) return s[x]=1;return vis[x]=1,false;
}
I bool FindCircle(CI x,CI lst)//32
{
	vis[x]=1;for(RI i=lnk[x];i;i=e[i].nxt) if(e[i].to^lst&&vis[e[i].to]) return FillCircle(x,x);// 
	for(RI i=lnk[x];i;i=e[i].nxt) if(e[i].to^lst&&FindCircle(e[i].to,x)) return true;return false;
}
int main()
{
	RI Tt,i,j,t1,t2;F.read(Tt);W(Tt--)
	{
		for(F.read(n),F.read(m),ee=0,i=1;i<=n;++i) s[i]=lnk[i]=deg[i]=vis[i]=tag[i]=0,fa[i]=i;//
		for(i=1;i<=m;++i) F.read(x[i]),F.read(y[i]),++deg[x[i]],++deg[y[i]];// 
		if(n==1) {F.writes("No\n");continue;}// 
		for(i=1;i<=n;++i) if(!(deg[i]%3)) {s[i]=1;goto End;}//30 
		if(n==2) {F.writes("No\n");continue;}//
		for(t2=0,i=1;i<=n;++i) deg[i]==2&&++t2;if(t2==n) {F.writes("No\n");continue;}// 
		for(i=1;i<=m;++i) deg[x[i]]%3==2&&deg[y[i]]%3==2&&
			(fa[getfa(x[i])]=getfa(y[i]),add(x[i],y[i]),add(y[i],x[i]));//32
		for(i=1;i<=n;++i) if(deg[i]%3==2&&!vis[i]&&FindCircle(i,0)) goto End;//32 
		for(i=1;i<=n;++i) vis[i]=0; 
		for(t1=t2=0,i=1;i<=n;++i) deg[i]==1&&++t1,deg[i]==2&&++t2;
		if(t1==2&&t2==n-2) {F.writes("No\n");continue;}//
		for(t1=0,i=1;i<=n;++i) deg[i]%3==1&&++t1;if(t1>1)//31
		{
			for(i=1;i<=m;++i) ((deg[x[i]]%3)^2||(deg[y[i]]%3)^2)&&(add(x[i],y[i]),add(y[i],x[i]));// 
			for(i=1;i<=n;++i) if(deg[i]%3==1) {FindLine(i);goto End;}// 
		} 
		for(t1=t2=0,i=1;i<=n;++i) deg[i]%3==1&&(t1=i),deg[i]==2&&++t2;
		if(deg[t1]==4&&t2==n-1) {F.writes("No\n");continue;}//
		for(s[t1]=1,t2=0,i=1;i<=m;++i) x[i]==t1&&(tag[p[++t2].v=y[i]]=1),y[i]==t1&&(tag[p[++t2].v=x[i]]=1);//31 
		for(i=1;i<=n;++i) deg[i]%3==2&&(fa[i]=getfa(i)); 
		for(t1=0,sort(p+1,p+t2+1),i=1;i<t2;++i) if(fa[p[i].v]==fa[p[i+1].v])
			if(FindOnTree(p[i].v,p[i].v),!t1) {t1=1;W(i<t2&&fa[p[i].v]==fa[p[i+1].v]) ++i;}else goto End;// 
		End:for(t1=0,i=1;i<=n;++i) !s[i]&&++t1;F.writes("Yes\n"),F.write(t1,'\n');// 
		for(i=1;i<=n;++i) !s[i]&&(F.write(i,' '),0);F.writes("\n");// 
	}return F.clear(),0;
}