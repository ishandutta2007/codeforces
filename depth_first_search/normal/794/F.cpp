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
#define LL long long
using namespace std;
int n,a[N+5];
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
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		#define PD(x) (T(x<<1,F[x]),T(x<<1|1,F[x]),Init(F[x]))
		LL S[N<<2],V[N<<2][10];int F[N<<2][10];I void Init(int* f) {for(RI i=0;i<=9;++i) f[i]=i;}
		I void PU(CI x) {S[x]=S[x<<1]+S[x<<1|1];for(RI i=0;i<=9;++i) V[x][i]=V[x<<1][i]+V[x<<1|1][i];}
		I void T(CI x,CI a,CI b)
		{
			for(RI i=0;i<=9;++i) F[x][i]==a&&(F[x][i]=b);S[x]+=V[x][a]*(b-a),V[x][b]+=V[x][a],V[x][a]=0;
		}
		LL tmp[10];I void T(CI x,int* f)
		{
			RI i;for(i=0;i<=9;++i) F[x][i]=f[F[x][i]];for(i=0;i<=9;++i) tmp[f[i]]+=V[x][i];
			for(S[x]=i=0;i<=9;++i) S[x]+=(V[x][i]=tmp[i])*i,tmp[i]=0;
		}
	public:
		I void Bd(PT)
		{
			if(Init(F[rt]),l==r) {for(RI i=1;a[l]>=i;i*=10) V[rt][(a[l]/i)%10]+=i;S[rt]=a[l];return;}
			RI mid=l+r>>1;Bd(LT),Bd(RT),PU(rt); 
		}
		I void U(CI L,CI R,CI a,CI b,PT)
		{
			if(L<=l&&r<=R) return T(rt,a,b);RI mid=l+r>>1;PD(rt),L<=mid&&(U(L,R,a,b,LT),0),R>mid&&(U(L,R,a,b,RT),0),PU(rt);
		}
		I LL Q(CI L,CI R,PT)
		{
			if(L<=l&&r<=R) return S[rt];RI mid=l+r>>1;PD(rt);return (L<=mid?Q(L,R,LT):0)+(R>mid?Q(L,R,RT):0);
		}
}S;
int main()
{
	RI Qt,i;for(read(n,Qt),i=1;i<=n;++i) read(a[i]);S.Bd();
	RI op,l,r,x,y;W(Qt--) read(op,l,r),op==1?(void)(read(x,y),x^y&&(S.U(l,r,x,y),0)):writeln(S.Q(l,r));return clear(),0;
}