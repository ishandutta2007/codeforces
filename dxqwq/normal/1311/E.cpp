// Problem: CF1311E Construct the Binary Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1311E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int mn[5003],mx[5003];
int d[5003],c[5003];
vector<int> v[5003];
signed main()
{
	for(int i=2; i<=5000; ++i) mx[i]=i*(i-1)>>1;
	for(int i=2; i<=5000; ++i) d[i]=d[i>>1]+1,mn[i]=mn[i-1]+d[i]; 
	c[0]=1,v[0].push_back(1);
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		if(mn[n]<=m&&m<=mx[n]) 
		{
			puts("YES");
			for(int i=1; i<n; ++i) c[i]=1;c[n]=0;
			for(int i=1; i<=mx[n]-m; ++i) 
			{
				bool F=0;
				for(int j=2; j<n; ++j) 
					if(c[j-2]*2>=c[j-1]+1&&(c[j]-1)*2>=c[j+1]) 
					{
						--c[j],++c[j-1],F=1;
						break;
					}
				if(!F) puts("FAIL");
			}
			int C=1;
			for(int i=1; i<n; ++i) v[i].clear();
			for(int i=1; i<n; ++i)
				for(int j=0; j<c[i]; ++j) 
					v[i].push_back(++C),printf("%d ",v[i-1][j/2]);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}