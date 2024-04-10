#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
#define LN 17
#define BS 40
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void read(Ty& x) {x=0;W(!isdigit(oc=tc()));W(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,Qt,sz,a[N+5],p[N+5],id[N+5],qk[N+5],ans[N+5];
struct OP {int x,y,k;bool operator < (Cn OP& o) Cn {return k>o.k;}}s[N*BS+5];
class LinkCutTree
{
	private:
		#define IR(x) (O[O[x].F].S[0]^x&&O[O[x].F].S[1]^x)
		#define Wh(x) (O[O[x].F].S[1]==x)
		#define Co(x,y,d) (O[O[x].F=y].S[d]=x)
		#define PU(x) (O[x].Sz=O[O[x].S[0]].Sz+O[O[x].S[1]].Sz+1)
		int St[N+5];struct node {int Sz,F,S[2];}O[N+5];
		I void Ro(RI x)
		{
			RI f=O[x].F,p=O[f].F,d=Wh(x);!IR(f)&&(O[p].S[Wh(f)]=x);
			O[x].F=p,Co(O[x].S[d^1],f,d),Co(f,x,d^1),PU(f);
		}
		I void S(RI x) {RI f;W(!IR(x)) f=O[x].F,!IR(f)&&(Ro(Wh(x)^Wh(f)?x:f),0),Ro(x);PU(x);}
		I void Ac(RI x) {for(RI y=0;x;x=O[y=x].F) S(x),O[x].S[1]=y,PU(x);}
	public:
		I void Link(CI x,CI y) {Ac(y),S(y),O[y].F=x;}
		I void Cut(CI x,CI y) {Ac(y),S(x),O[x].S[1]=O[y].F=0,PU(x);}
		I void Jump(int& x,int& t) {Ac(x),S(x),t+=O[x].Sz-1;W(O[x].S[0]) x=O[x].S[0];S(x);}
}LCT;
struct RMQ
{
	int Lg[N+5],V[LN+1][N+5];
	I void Init(RI op)
	{
		RI i,j;for(Lg[0]=-1,i=1;i<=n;++i) Lg[i]=Lg[i>>1]+1,V[0][i]=a[i]*op;
		for(j=1;(1<<j)<=n;++j) for(i=1;i+(1<<j)-1<=n;++i) V[j][i]=max(V[j-1][i],V[j-1][i+(1<<j-1)]);
	}
	I int Q(CI l,CI r) {RI k=Lg[r-l+1];return max(V[k][l],V[k][r-(1<<k)+1]);}
}R1,R2;
I void J(int& x,CI k) {RI l=x,r=n,u;W(l^r) u=l+r+1>>1,R1.Q(x,u)+R2.Q(x,u)<=k?l=u:r=u-1;x=l+1;}
bool cmpk(CI x,CI y) {return qk[x]<qk[y];}
int main()
{
	RI Qt,i,j,x;for(read(n,x,Qt),i=1;i<=n;++i) read(a[i]);R1.Init(1),R2.Init(-1); 
	for(i=1;i<=Qt;++i) read(qk[i]),qk[i]=x-qk[i],id[i]=i;sort(id+1,id+Qt+1,cmpk);
	RI c=0,mn,mx,lst;for(sz=sqrt(n)/8,i=1;i<=n;++i) for(mn=mx=a[i],lst=0,
		j=i+1;j<=min(n,i+sz);++j) mn=min(mn,a[j]),mx=max(mx,a[j]),mx-mn>lst&&(s[++c]=(OP){i,j,lst=mx-mn},0);
	RI t;for(sort(s+1,s+c+1),i=Qt,j=1;i;--i)
	{
		W(j<=c&&s[j].k>qk[id[i]]) p[s[j].x]&&(LCT.Cut(p[s[j].x],s[j].x),0),LCT.Link(p[s[j].x]=s[j].y,s[j].x),++j;
		t=0,x=1;W(x<=n) p[x]?LCT.Jump(x,t):(++t,J(x,qk[id[i]]));ans[id[i]]=t-1;
	}
	for(i=1;i<=Qt;++i) writeln(ans[i]);return clear(),0;
}