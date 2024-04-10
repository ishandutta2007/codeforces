#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
inline void readi(int &x);
int n;
struct node
{
	int a,b;
}p[100005];
int f[1000005];

bool cmp(node a,node b)
{return a.a<b.a;}

int main()
{
	readi(n);
	for(int i=1;i<=n;i++)
		readi(p[i].a),p[i].a++,readi(p[i].b);
	sort(p+1,p+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int low=0,high=n,mid;
		while(low+1<high)
		{
			mid=low+high>>1;
			if(p[mid].a<p[i].a-p[i].b)low=mid;
			else high=mid;
		}
		f[i]=f[low]+1;
		ans=max(ans,f[i]);
	}
	printf("%d\n",n-ans);
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}