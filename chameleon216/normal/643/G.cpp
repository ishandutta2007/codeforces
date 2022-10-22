#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char Get()
	{
//		return getchar();
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void Read(Tp& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void Put(char c)
	{
		if(r-ob==MB)fwrite(ob,1,MB,stdout),r=ob;
		*r++=c;
	}
	template<typename Tp>
	void Write(Tp& x)
	{
		if(x<0)Put('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
}IO;

const int MX=150100;
int N,M,P,A[MX];

struct Data
{
	int x[5],c[5];
	void Ins(int y,int d)
	{
		Fr(i,0,P-1)if(x[i]==y){c[i]+=d;return;}
		int n=d;
		Fr(i,0,P-1)if(c[i]<n)n=c[i];
		d-=n;
		Fr(i,0,P-1)c[i]-=n;
		if(!d)return;
		Fr(i,0,P-1)if(!c[i]){x[i]=y,c[i]=d;return;}
	}
};
Data operator+(Data a,const Data& b)
{
	Fr(i,0,P-1)if(b.c[i])a.Ins(b.x[i],b.c[i]);
	return a;
}

#define li (i<<1)
#define ri (i<<1|1)
struct SegmentTree
{
	Data v;
	int len,z;
	void Put(int x)
	{
		Fr(i,1,P-1)v.x[i]=v.c[i]=0;
		v.x[0]=x,v.c[0]=len,z=x;
	}
}T[MX*4];
inline void PushDown(int i)
{
	if(T[i].z)T[li].Put(T[i].z),T[ri].Put(T[i].z),T[i].z=0;
}
void Build(int i,int l,int r)
{
	T[i].len=r-l+1;
	if(l==r){T[i].v.Ins(A[l],1);return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	T[i].v=T[li].v+T[ri].v;
}
void Assign(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b){T[i].Put(x);return;}
	PushDown(i);
	int m=(l+r)>>1;
	if(a<=m)Assign(li,l,m,a,b,x);
	if(b>m)Assign(ri,m+1,r,a,b,x);
	T[i].v=T[li].v+T[ri].v;
}
Data Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return T[i].v;
	PushDown(i);
	int m=(l+r)>>1;
	if(b<=m)return Ask(li,l,m,a,b);
	if(a>m)return Ask(ri,m+1,r,a,b);
	return Ask(li,l,m,a,b)+Ask(ri,m+1,r,a,b);
}

/*void Print(int i,int l,int r)
{
	printf("[%d,%d]: laz=%d len=%d v=",l,r,T[i].z,T[i].len);
	Fr(j,0,P-1)printf("(%d,%d)",T[i].v.x[j],T[i].v.c[j]);
	putchar('\n');
	if(l==r)return;
	int m=(l+r)>>1;
	Print(li,l,m),Print(ri,m+1,r);
}*/

int main()
{
	IO.Read(N),IO.Read(M),IO.Read(P),P=100/P;
	Fr(i,1,N)IO.Read(A[i]);
	Build(1,1,N);
	int o,l,r,x;
	Fr(i,1,M)
	{
		IO.Read(o),IO.Read(l),IO.Read(r);
		if(o==1)IO.Read(x),Assign(1,1,N,l,r,x);
		else
		{
			Data d=Ask(1,1,N,l,r);
			
//			Fr(j,0,P-1)printf("(%d,%d)",d.x[j],d.c[j]);
//			putchar('\n');
			
			int c=0;
			Fr(j,0,P-1)if(d.c[j])++c;
			printf("%d ",c);
			Fr(j,0,P-1)if(d.c[j])printf("%d ",d.x[j]);
			putchar('\n');
		}
//		Print(1,1,N);
	}
	return 0;
}