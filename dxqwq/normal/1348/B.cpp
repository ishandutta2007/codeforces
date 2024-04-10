#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[100003];
int b[100003];
int main()
{
	int T=read();
	while(T--)
	{
		set<int> S;
		int n=read(),k=read();
		for(int i=1; i<=n; i++) a[i]=read(),S.insert(a[i]);
		if(S.size()>k) 
		{
			puts("-1");
			continue;
		}
		int sz=S.size();
		set<int>::iterator it;
		printf("%d\n",n*k);
		while(n--) 
		{
			for(it=S.begin(); it!=S.end(); it++) printf("%d ",*it); 
			for(int i=sz+1; i<=k; i++) printf("1 ");
		}
		puts("");
	}
	return 0;
}