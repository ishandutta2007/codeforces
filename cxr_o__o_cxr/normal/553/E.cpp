//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const double pi=acos(-1.0),inf=1e9;
struct complx{
	double x,y;
	complx(double xx=0,double yy=0):x(xx),y(yy){}
	inline complx operator +(const complx &a)const{
		return complx(x+a.x,y+a.y);
	}
	inline complx operator -(const complx &a)const{
		return complx(x-a.x,y-a.y);
	}
	inline complx operator *(const complx &a)const{
		return complx(x*a.x-y*a.y,x*a.y+y*a.x);
	}
};
const int N=104,M=1e5+4;
int n,m,t,fine,len,lim,rev[M],uu[N],vv[N],ww[N],d[N][N];
complx A[M],B[M];
double f[N][M],g[N][M],p[N][M];
inline void FFT(complx *a,int fl){
	for(int i=0;i<len;i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<lim-1);
		if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int mid=1;mid<len;mid<<=1){
		complx wn=complx(cos(pi/mid),fl*sin(pi/mid)),x,u,v;
		for(int i=0;i<len;i+=(mid<<1)){
			x=complx(1,0);
			for(int j=0;j<mid;j++,x=x*wn){
				u=a[i+j];v=x*a[i+j+mid];
				a[i+j]=u+v;a[i+j+mid]=u-v;
			}
		}
	}
}
inline void mul(int x){
	len=1;lim=0;
	while(len<=x){len<<=1;lim++;}
	FFT(A,1);FFT(B,1);
	for(int i=0;i<len;i++)A[i]=A[i]*B[i];
	FFT(A,-1);
	for(int i=0;i<len;i++)A[i].x/=len;
}
inline void clear(){
	for(int i=0;i<len;i++)A[i]=B[i]=complx(0,0);
}
inline void solve(int l,int r){
	if(l==t)return;
	if(l==r){
		for(int i=1;i<n;i++)f[i][r]=inf;
		for(int i=1;i<=m;i++)if(uu[i]!=n)
			f[uu[i]][r]=min(f[uu[i]][r],g[i][r]+ww[i]);
		return;
	}
	int mid=l+r>>1;
	solve(mid+1,r);
	for(int i=1;i<=m;i++)if(uu[i]!=n){
		for(int j=0;j<r-l;j++)A[j].x=p[i][j+1];
		for(int j=0;j<r-mid;j++)B[j].x=f[vv[i]][r-j];
		mul(r-l+r-mid);
		for(int j=l;j<=mid;j++)g[i][j]+=A[r-j-1].x;//
		clear();
	}
	solve(l,mid);
}
int main(){
//	freopen("1.in","r",stdin);
	n=read();m=read();t=read();fine=read();
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++){
		uu[i]=read();vv[i]=read();ww[i]=d[uu[i]][vv[i]]=read();
		for(int j=1;j<=t;j++)p[i][j]=(double)read()/1e5;
	} 
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=0;i<(t<<1);i++)f[n][i]=(i<=t)?0:fine;
	for(int i=1;i<n;i++)
		for(int j=t;j<(t<<1);j++)f[i][j]=d[i][n]+fine;
	solve(0,(t<<1)-1);
	printf("%.10lf",f[1][0]);
	return (0-0);
}