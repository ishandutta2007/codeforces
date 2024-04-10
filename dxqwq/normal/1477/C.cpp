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
int x[10003],y[10003];
bool f[10003];
long long dis(int A,int B)
{
	int p=abs(x[A]-x[B]),q=abs(y[A]-y[B]);
	return p*p+q*q;
}
int ans[10003],cnt;
void print(int x)
{
	ans[++cnt]=x;
}
void fff()
{
	for(int i=1; i<=cnt; i++) printf("%d ",ans[i]);
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) x[i]=read(),y[i]=read();
	print(1);
	f[1]=1;
	for(int i=1,lst=1,llst=-1; i<n; i++)
	{
		long long mn=-1;
		int k=0;
		for(int j=1; j<=n; j++) if(!f[j])
		{
			long long t=dis(lst,j);
			if(t>mn)
			{
				mn=t;
				k=j;
			}
		}
		f[k]=1;print(k);
		llst=lst,lst=k;
	}
	fff();
	return 0;
}