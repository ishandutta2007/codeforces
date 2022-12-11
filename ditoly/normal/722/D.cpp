#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#include<map>
using namespace std;
map<int,bool> mp;
#define MAXN 50000
int n,a[MAXN+5],c[MAXN+5],ans[MAXN+5];
bool check(int x)
{
	mp.clear();
	for(int i=0;i<n;i++)
	{
		for(c[i]=a[i];c[i]&&c[i]>x||mp[c[i]];c[i]>>=1);
		if(!c[i])return false;
		mp[c[i]]=1;
	}
	return true;
}
void save(){for(int i=0;i<n;i++)ans[i]=c[i];}
int main()
{
	int i,l,r,mid;
	l=n=read();
	for(i=r=0;i<n;i++)
	{
		a[i]=read();
		if(a[i]>r)r=a[i];
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))save(),r=mid-1;
		else l=mid+1;
	}
	for(i=0;i<n;i++)printf("%d ",ans[i]);
}