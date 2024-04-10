// Problem: C. Nastia and a Hidden Permutation
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
}int ans[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	if(n==2)
    	{
    		printf("? %d %d %d %d\n",2,1,2,1);
    		fflush(stdout);
    		int ans=read();
    		if(ans==1) puts("! 1 2");
    		else puts("! 2 1");
			fflush(stdout);
    		continue;
    	}
    	int POS_1=0;
    	for(int x=1,y=2; y<=n; x+=2,y+=2)
		{
			printf("? %d %d %d %d\n",2,x,y,1);
			fflush(stdout);
			int ans=read();
			// >1 1
			//result will be 2
			// 1 >1
			//result will be 1
			// 2 >2
			//result will be 2
			// >2 >1
			//result will be 3 or more
			if(ans>=3) continue;
			if(ans==1)
			{
				POS_1=x;
				break;
			}
			if(ans==2)
			{
				printf("? %d %d %d %d\n",2,y,x,1);
				fflush(stdout);
				int ans=read();
				if(ans==1) 
				{
					POS_1=y;
					break;
				}
			}
		}
		for(int i=1; i<=n; ++i) ans[i]=0;
		if(!POS_1) POS_1=n;
		ans[POS_1]=1;
		for(int i=1; i<=n; ++i) if(!ans[i])
		{
			printf("? %d %d %d %d\n",1,POS_1,i,n-1);
			fflush(stdout);
			ans[i]=read();
		}
		printf("! ");
		for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
		puts("");
		fflush(stdout);
    }
	return 0;
}