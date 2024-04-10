//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
void read(int &x)
{
	char c=getchar();
	int xx=1;
	x=0;
	while(('0'>c||'9'<c)&&c!='-')
	{
		c=getchar();
	}
	if(c=='-')
	{
		xx=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+('0'^c);
		c=getchar();
	}
	x*=xx;
}
void write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	char TMP[100];
	int cnt=0;
	while(x)
	{
		TMP[++cnt]=x%10+'0';
		x/=10;
	}
	while(cnt)
	{
		putchar(TMP[cnt--]);
	}
}
int n,a[100005],sum[100005],ans,l;
struct B{
	int v,p;
	bool operator < (const B &TMP)const
	{
		return v>TMP.v;
	}
}b[100005];
signed main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		b[i].v=sum[i]=sum[i-1]+a[i];
		b[i].p=i;
	}
	//now=(sum[r]-sum[l-1])*2-sum[n];
	sort(b,b+1+n);
	l=n;
	for(int r=n;r>=1;--r)
	{
		while(b[l].p>r)
		{
			--l;
		}
		ans=max(ans,(sum[r]-b[l].v)*2-sum[n]);
	}
	write(ans);
	return 0;
}