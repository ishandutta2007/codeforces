#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
//typedef long double ld;
typedef long long ll;
const double Pi=acos(-1);
const int X=1<<18|100;

int n,m,q,N,M;
int a[100010],b[100010];
namespace FFT{

struct C{
	double x,y;
};
C operator+(C x,C y){return (C){x.x+y.x,x.y+y.y};}
C operator-(C x,C y){return (C){x.x-y.x,x.y-y.y};}
C operator*(C x,C y){return (C){x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x};}

C Wn[X];
int maxw,btw,id[X];
void init(int x){
	for (maxw=1,btw=0;maxw<=x;maxw<<=1,btw++);
	for (int i=1;i<maxw;i++) id[i]=(id[i>>1]>>1)|((i&1)<<btw-1);
	for (int i=0;i<=maxw;i++) Wn[i]=(C){cos(2*Pi*i/maxw),sin(2*Pi*i/maxw)};
}
void fft(C *w,int tp){
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int md=1,len=2;md<maxw;md=len,len<<=1)
		for (int l=0,stp=maxw/len*tp;l<maxw;l+=len)
			for (int u=l,cur=~tp?0:maxw;u-l<md;u++,cur+=stp){
				static C x,y;
				x=w[u],y=Wn[cur]*w[u+md];
				w[u]=x+y; w[u+md]=x-y;
			}
}

}
using namespace FFT;

int A[100010],B[100010],_C[100010],D[100010],E[100010],F[100010];
C P[X],Q[X],S[X],T[X],R[X];
ll U[200010],V[200010];
int main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read(),N=max(N,a[i]);
	for (int i=1;i<=m;i++) b[i]=read(),M=max(M,b[i]);
	init(N+M+10);
	for (int i=1;i<=n;i++){
		A[a[i]]++;
		if (i<n){
			B[max(a[i],a[i+1])]++;
			_C[min(a[i],a[i+1])]++;
		}
	}
	for (int i=1;i<=m;i++){
		D[b[i]]++;
		if (i<m){
			E[max(b[i],b[i+1])]++;
			F[min(b[i],b[i+1])]++;
		}
	}
	//printf("A-B: "); for (int i=1;i<=N;i++) printf("%d ",A[i]-B[i]); puts("");
	//printf("A-C: "); for (int i=1;i<=N;i++) printf("%d ",A[i]-_C[i]); puts("");
	//printf("D-E: "); for (int i=1;i<=M;i++) printf("%d ",D[i]-E[i]); puts("");
	//printf("D-F: "); for (int i=1;i<=M;i++) printf("%d ",D[i]-F[i]); puts("");
	for (int i=1;i<=N;i++) P[i]=(C){0.0+A[i]-B[i],0.0+A[i]-_C[i]};
	for (int i=1;i<=M;i++) Q[i]=(C){0.0+D[i]-E[i],0.0+D[i]-F[i]};
	fft(P,1); fft(Q,1);
	for (int i=0;i<maxw;i++){
		int j=(maxw-i)&(maxw-1);
		if (i>j) continue;
		S[i]=(C){0.5*(P[i].x+P[j].x),0.5*(P[i].y-P[j].y)}*(C){0.5*(Q[i].x+Q[j].x),0.5*(Q[i].y-Q[j].y)};
		T[i]=(C){0.5*(P[i].y+P[j].y),0.5*(-P[i].x+P[j].x)}*(C){0.5*(Q[i].y+Q[j].y),0.5*(-Q[i].x+Q[j].x)};
		R[i]=(C){S[i].x-T[i].y,S[i].y+T[i].x};
		if (i^j) R[j]=(C){S[i].x+T[i].y,T[i].x-S[i].y};
	}
	fft(R,-1);
	for (int i=N+M;i>=2;i--){
		U[i]=round(R[i].x/maxw),V[i]=round(R[i].y/maxw);
	}
	for (int i=3;i<=N+M+1;i++) U[i]+=U[i-1];
	for (int i=N+M-1;i>=0;i--) V[i]+=V[i+1];
	
	//for (int i=0;i<=N+M;i++)
	//	printf("%d: U %lld V %lld\n",i,U[i],V[i]);
	
	while (q--){
		int x=min(read(),N+M+1);
		printf("%I64d\n",V[x]-U[x-1]);  //I64d
	}
	return 0;
}