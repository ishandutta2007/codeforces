#include<cstdio>
#define N 2010
using namespace std;
int n,T,w,k,cnt,len,t[N];
long long x,y,ss[N],ans[N];
char s[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld%s",&n,&k,&x,s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='*') cnt++;
			else t[++len]=cnt*k+1,cnt=0;
		t[++len]=cnt*k+1;
		y=x;
		for(w=len;w&&x;w--) x/=t[w];
		ss[len+1]=1;
		for(int i=len;i>w;i--) ss[i]=t[i]*ss[i+1];
		for(int i=w+1;i<=len;i++)
			ans[i]=(y-1)/ss[i+1],y-=ans[i]*ss[i+1];
		for(int i=1;i<=len;i++)
		{
			for(int j=1;j<=ans[i];j++) putchar('b');
			if(i!=len) putchar('a');
		}
		putchar('\n');
		cnt=len=0;
		for(int i=1;i<=n;i++) ans[i]=ss[i]=t[i]=0;
	}
}