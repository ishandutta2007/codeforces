#include<iostream>
using namespace std;
#define MN 1000
#define MV 2000
#define ME 5000000
string s[MN+5][2],sa,sb;
struct edge{int nx,t;}e[ME*2+5];
int h[MV+5],en,d[MV+5],l[MV+5],cnt,z[MV+5],zn,inz[MV+5],b[MV+5],bn;
int rh[MV+5],r[MV+5],c[MV+5],q[MV+5],qn;
inline void ins(int*h,int x,int y){e[++en]=(edge){h[x],y};h[x]=en;}
void tj(int x)
{
	d[x]=l[x]=++cnt;inz[z[zn++]=x]=1;
	for(int i=h[x];i;i=e[i].nx)
	{
		if(!d[e[i].t])tj(e[i].t);
		if(inz[e[i].t]&&l[e[i].t]<l[x])l[x]=l[e[i].t];
	}
	if(d[x]==l[x])for(++bn;z[zn]!=x;inz[z[zn]]=0)b[z[--zn]]=bn;
}
int main()
{
	int n,i,j,k;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>sa>>sb;
		s[i][0]=s[i][1]=s[i][0]+sa[0]+sa[1];
		s[i][0]+=sa[2];s[i][1]+=sb[0];
	}
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(i!=j)
	{
		if(s[i][0]==s[j][0])ins(h,i,j+n),ins(h,i+n,j+n);
		if(s[i][0]==s[j][1])ins(h,i,j);
		if(s[i][1]==s[j][0])ins(h,i+n,j+n);
		if(s[i][1]==s[j][1])ins(h,i+n,j);
	}
	for(i=1;i<=n<<1;++i)if(!d[i])tj(i);
	for(i=1;i<=n;++i)if(b[i]==b[i+n])return puts("NO"),0;
	puts("YES");
	for(i=1;i<=n<<1;++i)for(j=h[i];j;j=e[j].nx)
		if(b[i]!=b[e[j].t])ins(rh,b[e[j].t],b[i]),++r[b[i]];
	for(i=1;i<=bn;++i)if(!r[i])q[++qn]=i;
	for(i=1;i<=qn;++i)
	{
		if(!c[q[i]])
		{
			for(j=1;j<=n;++j)if(b[j]==q[i])c[b[j+n]]=1;
			for(;j<=n<<1;++j)if(b[j]==q[i])c[b[j-n]]=1;
		}
		for(j=rh[q[i]];j;j=e[j].nx)if(!--r[e[j].t])q[++qn]=e[j].t;
	}
	for(i=1;i<=n;++i)cout<<(c[b[i]]?s[i][1]:s[i][0])<<endl;
}