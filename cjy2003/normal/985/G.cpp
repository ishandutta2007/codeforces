#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian
{
	int to,nxt;
}bi[400040];
struct argue
{
	int x,y;
	friend bool operator < (argue a,argue b)
	{
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;	
	}
}p[400040];
int n,m,d[200020],st[200020],tp,cnt;
unsigned long long ans,A,B,C,hw[200020],qw[200020];
bool bj[200020];
int head[200020],num;
void add(int from,int to)
{
	bi[++num].nxt=head[from];
	head[from]=num;
	bi[num].to=to;
}
void calc(int i,int j,int k)
{
    if(i>j)swap(i,j);
    if(i>k)swap(i,k);
    if(j>k)swap(j,k);
    ans-=A*i+B*j+C*k;
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%llu %llu %llu",&A,&B,&C);
	for(int i=0;i<n;++i)
	{
		ans+=1ull*(n-i-1)*(n-i-2)/2ull*A*i;
		ans+=1ull*i*(n-i-1)*B*i;
		ans+=1ull*i*(i-1)/2ull*C*i;	
		if(i)qw[i]=qw[i-1]+i;
//		printf("%llu\n",ans);
	}
//	printf("%llu\n",ans);
	for(int i=n-1;i>=0;--i)
		hw[i]=hw[i+1]+i;
	int x,y;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		if(x>y)swap(x,y);
		p[++cnt].x=x,p[cnt].y=y;
		p[++cnt].x=y,p[cnt].y=x;
		++d[x],++d[y];
	}
	sort(p+1,p+1+cnt);
	int last=1;
	for(int i=0,j;i<n;++i)
		while(p[last].x==i&&last<=cnt)
		{
			j=p[last].y;
			if(i>j)
			{
				++last;
				continue;	
			}
			ans-=A*(n-j-1)*i;
			ans-=B*(n-j-1)*j;
			ans-=C*hw[j+1];
			ans-=A*(j-i-1)*i;
			ans-=B*(qw[j-1]-qw[i]);
			ans-=C*(j-i-1)*j;
			if(i)
			{
				ans-=A*qw[i-1];
				ans-=B*i*i;
				ans-=C*i*j;		
			}
			++last;
		}
	last=1;
	for(int i=0,j;i<n;++i)
	{
		int cl=0,cr=0;
		unsigned long long hl=0,hr=0;
		while(p[last].x==i&&last<=cnt)
		{
			j=p[last].y;
			if(j<i)
			{
				ans+=hl*A;
				ans+=cl*B*j;
				ans+=cl*C*i;
				++cl,hl+=j;
			}
			else
			{
				ans+=hl*A;
				ans+=cl*B*i;
				ans+=cl*C*j;
				ans+=cr*A*i;
				ans+=hr*B;
				ans+=cr*C*j;
				++cr,hr+=j;
			}
			++last;
		}
	}
	last=1;
	for(int i=0;i<n;++i)
		while(p[last].x==i&&last<=cnt)
		{
			if(d[p[last].y]>d[i]||(d[p[last].y]==d[i]&&p[last].y>i))add(i,p[last].y);
			++last;
		}
	for(int i=0;i<n;++i)
	{
		for(int j=head[i];j;j=bi[j].nxt)bj[bi[j].to]=1;
		for(int j=head[i];j;j=bi[j].nxt)
			for(int k=head[bi[j].to];k;k=bi[k].nxt)
				if(bj[bi[k].to])calc(i,bi[j].to,bi[k].to);
		for(int j=head[i];j;j=bi[j].nxt)bj[bi[j].to]=0;
	}
	printf("%llu",ans);
	return 0;
}