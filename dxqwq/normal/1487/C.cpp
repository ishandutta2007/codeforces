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
int a[100003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1; i<=n; i++) a[i]=0;
		int win=0,draw=n*(n-1)/2,score=n-1;
		for(int i=n*(n-1)/2; i>0; i--)
		if(i%n==0) {win=i,draw=n*(n-1)/2-win,score=i/n+n-1;
		break;}
		for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++)
		{
			if(win&&a[i]+3<=score) printf("1 "),a[i]+=3,--win;
			else if(draw&&a[i]+1<=score) printf("0 "),++a[i],++a[j],--draw;
			else printf("-1 "),a[j]+=3,--win;
		}
		puts("");	
	}
	return 0;
}