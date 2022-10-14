#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long s=0, w=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}
long long n,k,a[1100],p[1100];
int main()
{
	long long T=read();
	while(T--)
	{
		n=read(),k=read();
		for(int i=1; i<=n; i++) a[i]=read();
		memset(p,0,sizeof(p));
		bool flag=0;
		for(int i=1; i<=n; i++)
		{
			long long x=a[i],pp=0;
			while(x)
			{
				p[pp]+=x%k;
				if(p[pp]>1) {flag=1; break; }
				pp++, x/=k;
			}
			if(flag) break;
		}
		(flag)?puts("NO"):puts("YES");
	}
	return 0;
}