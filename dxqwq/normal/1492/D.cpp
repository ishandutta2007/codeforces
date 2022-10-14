#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char a1[1000003],a2[1000003];
int c1=0,c2=0;
void out(int x)
{
	a1[++c1]='1';
	for(int i=1; i<=x; i++) a1[++c1]='0',a2[++c2]='0';
	a2[++c2]='1';
	return ;
}
signed main()
{
	int n=read(),m=read(),k=read();
	if(k==0)
	{
		puts("YES");
		
		for(int i=1; i<=m; i++) printf("1");
		for(int i=1; i<=n; i++) printf("0");
		puts("");
		
		for(int i=1; i<=m; i++) printf("1");
		for(int i=1; i<=n; i++) printf("0");
		puts("");
		return 0;
	}
	if(m==1)
	{
		if(k==0)
		{
			puts("YES");
			printf("1");
			for(int i=1; i<=n; i++) printf("0");
			puts("");
			printf("1");
			for(int i=1; i<=n; i++) printf("0");
			puts("");
		}
		else puts("NO");
		return 0;
	}
	if(n==0)
	{
		if(k==0)
		{
			puts("YES");
			for(int i=1; i<=m; i++) printf("1");
			puts("");
			for(int i=1; i<=m; i++) printf("1");
			puts("");
		}
		else puts("NO");
		return 0;
	}
	--m;
	//100110
	//011001
	int ans=n+m-1;
	if(ans>=k)
	{
		puts("YES");
		--n,--m;
		int A=ans-k;//
		printf("1");
		int c=n,d=m;
		for(int i=1; i<=min(A,n); ++i) --c,printf("0");
		if(A>n) for(int i=1; i<=A-n; ++i) --d,printf("1");
		printf("1");
		for(int i=1; i<=c; i++) printf("0");
		for(int i=1; i<=d; i++) printf("1");
		printf("0");
		puts("");
		printf("1");
		for(int i=1; i<=min(A,n); ++i) printf("0");
		if(A>n) for(int i=1; i<=A-n; ++i) printf("1");
		printf("0");
		for(int i=1; i<=c; i++) printf("0");
		for(int i=1; i<=d; i++) printf("1");
		printf("1");
		puts("");
	}
	else puts("NO");
    return 0;
}
//11010
//10011