// Problem: C. Laboratory Work
// Contest: Codeforces - Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// URL: https://codeforces.com/contest/931/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	int x=1000000000000ll;
	for(int i=1; i<=n; i++) x=min(x,a[i]);
	for(int i=1; i<=n; i++) a[i]-=x;
	int y=0;
	for(int i=1; i<=n; i++) y=max(y,a[i]);
	if(y<=1)
	{
		printf("%lld\n",n);
		for(int i=1; i<=n; i++) printf("%lld ",x+a[i]);
		return 0;
	}
	int A=0,B=0,AA=0,AAA=0;
	for(int i=1; i<=n; i++) if(a[i]==1) ++B;
	else if(a[i]==0) ++AA;
	else ++AAA;
	if(B%2==1) --B;
	A=min(AA,AAA);
	A<<=1;
	printf("%lld\n",n-max(A,B));
	if(A>=B)
	{
		A>>=1;
		int t1=1,t2=1;
		for(int i=1; i<=n; i++) if(a[i]==0)
		{
			if(t1<=A) 
			{
				printf("%lld ",x+1);
				++t1;
			}
			else printf("%lld ",x);
		}
		else if(a[i]==2)
		{
			if(t2<=A) 
			{
				printf("%lld ",x+1);
				++t2;
			}
			else printf("%lld ",x+2);
		}
		else printf("%lld ",x+a[i]);
	}
	else
	{
		int bb=1;
		for(int i=1; i<=n; i++) if(a[i]==1)
		{
			if(bb<=B)
			{
				if(bb%2==1) printf("%lld ",x+2);
				else printf("%lld ",x);
				++bb;
			}
			else printf("%lld\n",x+1);
		}
		else printf("%lld ",x+a[i]);
	}
    return 0;
}