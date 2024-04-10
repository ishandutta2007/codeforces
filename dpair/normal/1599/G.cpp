//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
struct pnt
{
	ll x,y;char operator==(pnt b) {return x==b.x&&y==b.y;}
	char operator<(pnt b) {return x^b.x?x<b.x:y<b.y;}
	inline pnt operator+(pnt b) {return(pnt){x+b.x,y+b.y};}
	inline pnt operator-(pnt b) {return(pnt){x-b.x,y-b.y};}
	inline ll operator*(pnt b) {return x*b.y-y*b.x;}
	inline double abs() {return sqrt(x*x+y*y);}
	inline double operator^(pnt b) {return(*this-b).abs();}
}a[200005],p;int n,st,wh=0;
int main()
{
	read(n,st);for(int i=1;i<=n;i++) read(a[i].x,a[i].y);
	if(n==3)
	{
		int u,v;if(st==1) u=2,v=3;else if(st==2) u=1,v=3;else if(st==3) u=1,v=2;
		return printf("%.10lf\n",min((a[st]^a[u]),(a[st]^a[v]))+(a[u]^a[v])),0;
	}pnt qwq=a[st];
	if((a[2]-a[1])*(a[3]-a[2])!=0&&(a[4]-a[3])*(a[3]-a[2])==0) wh=1;
	else for(int i=3;i<=n;i++) if((a[i]-a[1])*(a[2]-a[1])) {wh=i;break;}
	p=a[wh],n--;for(int i=wh;i<=n;i++) a[i]=a[i+1];
	sort(a+1,a+n+1),a[n+1]=(pnt){0,0};
	for(int i=1;i<=n;i++) if(a[i]==qwq) {st=i;break;}
	if(qwq==p) return printf("%.10lf\n",min((p^a[1]),(p^a[n]))+(a[1]^a[n])),0;
	//if(st==wh) return printf("%.10lf\n",min((p^a[1]),(p^a[n]))+(a[1]^a[n])),0;
	double rs=1e18;
	rs=min(rs,(a[st]^a[1])+(a[1]^a[n])+(a[n]^p));
	rs=min(rs,(a[st]^a[n])+(a[n]^a[1])+(a[1]^p));
	rs=min(rs,(a[st]^a[1])+(a[1]^p)+(st==n?0:min(p^a[st+1],p^a[n])+(a[st+1]^a[n])));
	//printf("! %d\n",st);
	//printf("%.10lf\n",(a[st]^a[1])+(a[1]^a[2])+(a[2]^p)+min(a[2+1]^p,a[n]^p)+(a[n]^a[2+1]));
	for(int i=st+1;i<n;i++) rs=min(rs,(a[st]^a[1])+(a[1]^a[i])+(a[i]^p)+min(a[i+1]^p,a[n]^p)+(a[n]^a[i+1]));
	rs=min(rs,(a[st]^a[n])+(a[n]^p)+(st==1?0:min(p^a[st-1],p^a[1])+(a[st-1]^a[1])));
	for(int i=1+1;i<st;i++) rs=min(rs,(a[st]^a[n])+(a[n]^a[i])+(a[i]^p)+min(a[i-1]^p,a[1]^p)+(a[1]^a[i-1]));
	return printf("%.10lf\n",rs),0;
}