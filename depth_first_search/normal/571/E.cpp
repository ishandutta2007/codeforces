#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
#define S 50000
#define X 1000000007
#define int long long
#define NA() (puts("-1"),exit(0),0)
using namespace std;
int n,a[N+5],b[N+5],A[S+5],B[S+5],P[S+5],Q[S+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=t*x%X),x=x*x%X,y>>=1;return t;}
I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;} 
I void exgcd(CI x,CI y,int& a,int& b) {y?(exgcd(y,x%y,b,a),b-=x/y*a):(a=1,b=0);}
namespace Prime
{
	int Pt,Pr[S+5];I int IsP(CI x) {for(RI i=2;i*i<=x;++i) if(!(x%i)) return 0;return 1;}
	int cnt;I void Init() {for(RI i=2;i<=31622;++i) IsP(i)&&(Pr[++Pt]=i);cnt=Pt;}
	map<int,int> id;I int ID(CI x) {return !id[x]&&(Pr[id[x]=++cnt]=x),id[x];}
	I void Work(int* V,RI x) {for(RI i=1;i<=Pt;++i) W(!(x%Pr[i])) x/=Pr[i],++V[i];x^1&&++V[ID(x)];}
}
namespace Equation
{
	int tot;struct Data
	{
		int a,b,c;I Data(CI x=0,CI y=0,CI z=0):a(x),b(y),c(z){}
		I bool operator < (Con Data& o) Con {return a^o.a?a<o.a:(b^o.b?b<o.b:c<o.c);}
	}s[S+5];set<Data> vis;
	I void Add(CI a,CI b,CI c)
	{
		RI g=abs(gcd(a,b));c%g&&NA();Data t(a/g,b/g,c/g);
		!vis.count(t)&&(vis.insert(s[++tot]=t),0);
	}
	I void Solve(int& x,int& y)
	{
		RI i,p=s[1].c*s[2].b-s[1].b*s[2].c,q=s[1].a*s[2].b-s[1].b*s[2].a;
		(!q||p%q)&&NA(),x=p/q,(s[1].c-s[1].a*x)%s[1].b&&NA(),y=(s[1].c-s[1].a*x)/s[1].b;
		for(i=3;i<=tot;++i) (s[1].a*x+s[1].b*y)^s[1].c&&NA();
	}
}
signed main()
{
	using namespace Prime;using namespace Equation;
	RI i,j,x,y;for(scanf("%lld",&n),i=1;i<=n;++i) scanf("%lld%lld",a+i,b+i);
	RI u,v,t,fg;for(Init(),i=1;i<=n;++i)
	{
		memset(A,0,sizeof(A)),memset(B,0,sizeof(B)),Work(A,a[i]),Work(B,b[i]);
		if(i==1) {for(j=1;j<=Pt+cnt;++j) P[j]=A[j],Q[j]=B[j];continue;}
		for(u=v=-1,fg=0,j=1;j<=Pt+cnt;++j) if(B[j]||Q[j])
		{
			fg=1;if(!B[j]) {((t=A[j]-P[j])<0||t%Q[j])&&NA(),v=t/Q[j];break;}
			if(!Q[j]) {((t=P[j]-A[j])<0||t%B[j])&&NA(),u=t/B[j];break;}
		}else A[j]^P[j]&&NA();
		if(!fg) continue;if(~u||~v)
		{
			if(!~u) for(j=1;j<=Pt+cnt;++j) if(B[j])
				{((t=P[j]+v*Q[j]-A[j])<0||t%B[j])&&NA(),u=t/B[j];break;}
			if(!~v) for(j=1;j<=Pt+cnt;++j) if(Q[j])
				{((t=A[j]+u*B[j]-P[j])<0||t%Q[j])&&NA(),v=t/Q[j];break;}
			for(j=1;j<=Pt+cnt;++j) (A[j]+u*B[j])^(P[j]+=v*Q[j])&&NA();goto End;
		}
		for(tot=0,vis.clear(),j=1;j<=Pt+cnt;++j) (B[j]||Q[j])&&(Add(B[j],-Q[j],P[j]-A[j]),0);
		if(tot==1)
		{
			exgcd(s[1].a,s[1].b*=-1,u,v),u*=s[1].c,v*=-s[1].c;
			t=max(u<0?(-u-1)/s[1].b+1:0,v<0?(-v-1)/s[1].a+1:0),u+=t*s[1].b,v+=t*s[1].a;
			(u<0||v<0)&&NA(),t=min(u/s[1].b,v/s[1].a),u-=t*s[1].b,v-=t*s[1].a;
			for(j=1;j<=Pt+cnt;++j) P[j]+=v*Q[j];goto End;
		}
		for(Solve(u,v),j=1;j<=Pt+cnt;++j) P[j]+=v*Q[j];
		End:for(j=1;j<=Pt+cnt;++j) (B[j]||Q[j])&&(Q[j]*=B[j]/gcd(B[j],Q[j]));
	}
	for(t=i=1;i<=Pt+cnt;++i) (t*=QP(Pr[i],P[i]))%=X;return printf("%lld\n",t),0;
}