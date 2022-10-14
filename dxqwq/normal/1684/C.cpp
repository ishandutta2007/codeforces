//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> a[200003],b[200003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i)
			a[i].resize(m+3),b[i].resize(m+3);
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				b[i][j]=a[i][j]=read();
		for(int i=1; i<=n; ++i)
			sort(b[i].begin()+1,b[i].begin()+m+1);
		int P=1,Q=1;
		for(int i=1; i<=n; ++i)
		{
			int A=0,B=0,C=0;
			for(int j=1; j<=m; ++j)
				if(a[i][j]!=b[i][j])
					if(!A) A=j;
					else if(!B) B=j;
					else
					{
						C=1;
						break;
					}
			if(C) {P=-1;Q=-1;break;}
			else if(A)
			{
				P=A,Q=B;break;
			}
		}
		if(P==-1)
		{
			puts("-1");continue;
		}
		for(int i=1; i<=n; ++i)
			swap(a[i][P],a[i][Q]);
		for(int i=1; i<=n; ++i)
		{
			int A=0;
			for(int j=1; j<=m; ++j)
				if(a[i][j]!=b[i][j])
					if(!A) 
					{
						A=1;break;
					}
			if(A)
			{
				P=-1;break;
			}
		}	
		if(P==-1) puts("-1");
		else printf("%d %d\n",P,Q);
	}
	return 0;
}