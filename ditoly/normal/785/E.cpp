#include<cstdio>
#include<algorithm>
using namespace std;
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 200000
#define ND 6000000
#define L(x) c[x][0]
#define R(x) c[x][1]
int fa[ND+5],c[ND+5][2],s[ND+5],z[ND+5],p[ND+5];
int t[MN+5],tn=MN;
inline int ran()
{
	static int x=23333;
	return x^=x<<13,x^=x>>17,x^=x<<5;
}
inline void up(int x){s[x]=s[L(x)]+s[R(x)]+1;}
void rotate(int x)
{
	int f=fa[x],ff=fa[f],l=R(f)==x,r=l^1;
	fa[f]=x;fa[x]=ff;fa[c[x][r]]=f;
	c[ff][R(ff)==f]=x;c[f][l]=c[x][r];c[x][r]=f;
	up(f);up(x);
}
void ins(int f,int t,int x)
{
	while(c[f][t])t=x>z[f=c[f][t]],++s[f];
	fa[c[f][t]=++tn]=f;p[tn]=ran();z[tn]=x;s[tn]=1;
	for(;fa[tn]>MN&&p[tn]>p[fa[tn]];)rotate(tn);
}
int find(int x,int k)
{
	while(z[x]!=k)x=k<z[x]?L(x):R(x);
	return x;
}
void del(int x)
{
	while(L(x)||R(x))rotate(p[L(x)]>p[R(x)]?L(x):R(x));
	c[fa[x]][R(fa[x])==x]=0;
	while(x=fa[x])up(x);
}
int get(int x,int t)
{
	return x?z[x]>t?get(L(x),t):s[L(x)]+1+get(R(x),t):0;
}
void ins(int x,int z){for(;x<=MN;x+=x&-x)ins(x,0,z);}
void del(int x,int z){for(;x<=MN;x+=x&-x)del(find(L(x),z));}
int sum(int x,int z){int r=0;for(;x;x-=x&-x)r+=get(L(x),z);return r;}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,m,i,x,y;long long ans=0;
	n=read();m=read();p[0]=0x80000000;
	for(i=1;i<=n;++i)t[i]=i,ins(i,i);
	while(m--)
	{
		x=read();y=read();if(x>y)swap(x,y);
		if(x<y)
		{
			ans+=((sum(y-1,t[y])-sum(x,t[y])-sum(y,t[x])+sum(x,t[x]))<<1)+1;
			del(x,t[x]);del(y,t[y]);
			swap(t[x],t[y]);
			ins(x,t[x]);ins(y,t[y]);
		}
		printf("%I64d\n",ans);
	}
}