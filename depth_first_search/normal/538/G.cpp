#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define M 2000000
#define LL long long
#define eps 1e-12
using namespace std;
int n,m,t1[M+5],t2[M+5];
struct Data
{
	int x;LL A,B;I Data(CI t=0,LL a=0,LL b=0):x(t),A(a),B(b){}
	I bool operator < (Con Data& o) Con {return x<o.x;}
}s1[N+5],s2[N+5];
LL f[N+5];I bool Try(Data* s,int* t,CI x)
{
	RI i,j;LL k;for(i=1;i<=n+1;++i) f[i]=s[i].B-s[i].A*x;for(i=1;i<=m;++i) t[i]=0;
	for(i=1;i<=n+1;++i) if((k=(f[i]-f[i-1])+(s[i].x-s[i-1].x))&1)
		return 0; else for(k>>=1,j=1;j<=k;++j) t[s[i-1].x+j]=1;return 1;
}
I void Work(Data* s,int* t)
{
	#define NA() (puts("NO"),exit(0))
	RI i,j;LL L=-m,R=m;for(sort(s+1,s+n+1),s[n+1]=Data(m,-1,0),i=1;i<=n+1&&L<=R;++i)
	{
		if(s[i-1].A==s[i].A) {if(abs(s[i-1].B-s[i].B)>s[i].x-s[i-1].x) NA();}
		else s[i-1].A<s[i].A?
		(
			L=max(L,(LL)ceil(1.0L*((s[i-1].x-s[i].x)-(s[i-1].B-s[i].B))/(s[i].A-s[i-1].A)-eps)),
			R=min(R,(LL)floor(1.0L*((s[i].x-s[i-1].x)-(s[i-1].B-s[i].B))/(s[i].A-s[i-1].A)+eps))
		):
		(
			L=max(L,(LL)ceil(1.0L*((s[i].x-s[i-1].x)-(s[i-1].B-s[i].B))/(s[i].A-s[i-1].A)-eps)),
			R=min(R,(LL)floor(1.0L*((s[i-1].x-s[i].x)-(s[i-1].B-s[i].B))/(s[i].A-s[i-1].A)+eps))
		);
	}
	if(L>R||(!Try(s,t,L)&&(L+1>R||!Try(s,t,L+1)))) NA();
}
int main()
{
	RI i;LL t,x,y;for(scanf("%d%d",&n,&m),i=1;i<=n;++i)
		scanf("%lld%lld%lld",&t,&x,&y),s1[i]=Data(t%m,t/m,x-y),s2[i]=Data(t%m,t/m,x+y);
	for(Work(s1,t1),Work(s2,t2),i=1;i<=m;++i)
		putchar(t1[i]?(t2[i]?'R':'D'):(t2[i]?'U':'L'));return 0;
}