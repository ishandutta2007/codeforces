#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 200000
#define SM 224
#define LL long long
using namespace std;
int n,pt,qt,a[N+5],b[N+5],c[N+5];struct Q {int p,x,y;I bool operator < (Cn Q& o) Cn {return x<o.x;}}p[N+5],q[N+5];
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
int o[SM+5],u[SM+1][SM+1],ut[SM+5],uc[SM+5],tg[N+5],id[N+5],A[N+5],B[N+5],C[N+5];LL f1[N+5],f2[N+5],f3,h[N+5],g1[N+5],g2[N+5],wx[N+5],wy[N+5];
int tA[N+5],tC[N+5],tA_b[SM+1][SM+1],tA_c[SM+1][SM+1],tC_a[SM+1][SM+1],tC_b[SM+1][SM+1];LL f1_[SM+1][SM+1],f2_[SM+1][SM+1],h_[SM+1][SM+1];
LL ans[N+5];I void Work()
{
	RI i,j,k,ot=0;for(i=1;i<=pt;++i) !tg[p[i].x]&&(tg[o[++ot]=p[i].x]=1);
	for(sort(o+1,o+ot+1),i=1;i<=ot;++i) id[o[i]]=i;for(i=1;i<=pt;++i) u[id[p[i].x]][++ut[id[p[i].x]]]=i;
	RI x,oi=0;LL t;for(sort(q+1,q+qt+1),i=j=1;i<=n;++i)
	{
		if(!tg[i]) A[i]=a[i],B[i]=b[a[i]],C[i]=c[a[i]],f3+=f2[C[i]],h[C[i]]+=tA[C[i]],f2[A[i]]+=f1[A[i]],++f1[B[i]],++tC[C[i]],++tA[A[i]];
		else for(++oi,k=0;k<=ut[oi];++k) x=k?p[u[oi][k]].y:a[i],
			tA_b[oi][k]=tA[b[x]],tA_c[oi][k]=tA[c[x]],tC_a[oi][k]=tC[x],tC_b[oi][k]=tC[b[x]],f1_[oi][k]=f1[x],f2_[oi][k]=f2[c[x]],h_[oi][k]=h[b[x]];
		W(j<=qt&&q[j].x==i)
		{
			for(t=f3,k=1;k<=oi;++k) A[o[k]]=a[o[k]],uc[k]=0;
			for(k=1;k<=pt&&p[k].p<q[j].p;++k) A[p[k].x]=p[k].y,++uc[id[p[k].x]];
			for(k=1;k<=oi;++k) B[o[k]]=b[A[o[k]]],C[o[k]]=c[A[o[k]]],
				t+=g2[C[o[k]]]+g1[A[o[k]]]*(tC[A[o[k]]]-tC_a[k][uc[k]]),g2[A[o[k]]]+=g1[A[o[k]]]+f1_[k][uc[k]],++g1[B[o[k]]],
				t+=wy[C[o[k]]]*tA_c[k][uc[k]]-wx[C[o[k]]],++wy[B[o[k]]],wx[B[o[k]]]+=tA_b[k][uc[k]];
			for(k=1;k<=oi;++k) t+=f2_[k][uc[k]]+f1_[k][uc[k]]*(tC[A[o[k]]]-tC_a[k][uc[k]]),
				t+=h[B[o[k]]]-h_[k][uc[k]]-1LL*tA_b[k][uc[k]]*(tC[B[o[k]]]-tC_b[k][uc[k]]);
			for(ans[q[j++].p]=t,k=1;k<=oi;++k) g1[B[o[k]]]=g2[A[o[k]]]=wx[B[o[k]]]=wy[B[o[k]]]=0;
		}
	}
	#define Cl(s) (memset(s,0,sizeof(s)))
	for(i=1;i<=qt;++i) writeln(ans[i]);for(i=1;i<=pt;++i) a[p[i].x]=p[i].y;for(i=1;i<=n;++i) tg[i]=f1[i]=f2[i]=f3=h[i]=tA[i]=tC[i]=0;
	for(i=1;i<=ot;++i) {for(j=0;j<=ut[i];++j) tA_b[i][j]=tA_c[i][j]=tC_a[i][j]=tC_b[i][j]=f1_[i][j]=f2_[i][j]=h_[i][j]=0;ut[i]=0;}
}
int main()
{
	RI Qt,i,sz,op;for(read(n,Qt),sz=sqrt(Qt),i=1;i<=n;++i) read(a[i]);for(i=1;i<=n;++i) read(b[i]);for(i=1;i<=n;++i) read(c[i]);
	W(Qt--) read(op),op==1?(p[++pt].p=qt,read(p[pt].x,p[pt].y)):(++qt,q[qt].p=qt,read(q[qt].x)),pt+qt==sz&&(Work(),pt=qt=0);return Work(),clear(),0;
}