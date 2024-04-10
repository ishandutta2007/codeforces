#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
template<class T> inline bool ten(T &x,const T &y){return y<x?x=y,1:0;}
template<class T> inline bool rel(T &x,const T &y){return x<y?x=y,1:0;}

template<class T> inline void readi(T &x)
{char c;bool fl;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));
if(c=='-')fl=1,x=0;else fl=0,x=c-'0';
while(c=getchar(),c>=0&&c<='9')x=x*10+c-'0';
if(fl)x=-x;}

int n,k,a[200005];

int main()
{
	scanf("%d%d",&n,&k); 
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int aa=2000000005;
	for(int i=1;i<=n;i++)aa=min(a[i],aa);
	LL ans=0;
	for(int i=1;i<=n;i++)
		if((a[i]-aa)%k!=0){puts("-1");return 0;}
		else ans+=(a[i]-aa)/k;
	cout<<ans<<endl;
	return 0;
}