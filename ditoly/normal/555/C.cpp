#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define N 262144
int x[MN+5],y[MN+5],cx[MN+5],cxn,cy[MN+5],cyn,t1[N*2+5],t2[N*2+5];
char c[MN+5];
void renew(int*t,int l,int r,int x)
{
	if(l<=r)for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)t[l+1]=max(t[l+1],x);
		if( r&1)t[r-1]=max(t[r-1],x);
	}
}
int query(int*t,int k)
{
	int res=0;
	for(k+=N;k;k>>=1)res=max(res,t[k]);
	return res;
}
int getx(int x){return upper_bound(cx+1,cx+cxn+1,x)-cx-1;}
int gety(int y){return lower_bound(cy+1,cy+cyn+1,y)-cy;}
int main()
{
	int n,q,i,z;
	n=read();q=read();
	for(i=1;i<=q;++i)cx[i]=x[i]=read(),cy[i]=y[i]=read(),c[i]=getchar();
	sort(cx+1,cx+q+1);cxn=unique(cx+1,cx+q+1)-cx-1;cx[++cxn]=n+1;
	sort(cy+1,cy+q+1);cyn=unique(cy+1,cy+q+1)-cy-1;cy[++cyn]=n+1;
	for(i=1;i<=q;++i)
		if(c[i]=='L')
		{
			z=query(t2,gety(y[i]));
			printf("%d\n",x[i]-z);
			renew(t1,getx(z),getx(x[i]),y[i]);
			z=gety(y[i]);
			renew(t2,z,z,x[i]);
		}
		else
		{
			z=query(t1,getx(x[i]));
			printf("%d\n",y[i]-z);
			renew(t2,gety(z),gety(y[i]),x[i]);
			z=getx(x[i]);
			renew(t1,z,z,y[i]);
		}
}