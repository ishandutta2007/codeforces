// Problem: C. Tree Diameter
// Contest: Codeforces - Forethought Future Cup - Elimination Round
// URL: https://codeforces.com/contest/1146/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}

signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),ans=0;
		for(int i=1; i<=n; i<<=1)
		{
			int A=0;int B=0;
			for(int j=1; j<=n; ++j)
			if(i&j) ++A;
			else ++B;
			printf("%d %d ",A,B);
			for(int j=1; j<=n; ++j)
			if(i&j) printf("%d ",j);
			for(int j=1; j<=n; ++j)
			if((i&j)==0) printf("%d ",j);
			puts("");
			fflush(stdout);
			ans=max(ans,read());
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
    return 0;
}