#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,cnt,p[400010];
char s[200010],t[400010];
int calc(int l,int r)
{
	l=2*l+1,r=2*r+1;
	if((l+r)/2+p[(l+r)/2]>r) return 1;
	return 0;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s+1);
		cnt=0;
		t[++cnt]='@';
		t[++cnt]='#';
		for(int i=1;i<=n;++i)
		{
			t[++cnt]=s[i];
			t[++cnt]='#';
		}
		t[++cnt]='$';
		int ans=0;
		for(int i=2,L,R=0;i<cnt;++i)
		{
			if(i<R) p[i]=min(R-i,p[2*L-i]);
			else p[i]=0;
			while(t[i+p[i]]==t[i-p[i]]) ++p[i];
			if(i+p[i]>R) R=i+p[i],L=i;
		}
		for(int i=1;i<=n;++i)
		{
			if(n%2 && i==(n+1)/2) {++ans;continue;}
			if(i<=n/2)
			{
				if(calc(i+1,n-(i-1))) ++ans;
			}
			else
			{
				if(calc(n-i+1,i-1)) ++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//ore no turn,draw!