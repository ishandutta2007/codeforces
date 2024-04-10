// Problem: E. Serval and Snake
// Contest: Codeforces - Codeforces Round #551 (Div. 2)
// URL: https://codeforces.com/contest/1153/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1003],b[1003];
//
signed main()
{
 	int n=read();
 	for(int i=1; i<=n; ++i) 
 	{
 		printf("? %d %d %d %d\n",i,1,i,n);
 		fflush(stdout);
 		a[i]=read();
 	}
 	//H
 	for(int i=1; i<=n; ++i) 
 	{
 		printf("? %d %d %d %d\n",1,i,n,i);
 		fflush(stdout);
 		b[i]=read();
 	}
 	//S
 	int A=0,B=0,C=0,D=0;
 	for(int i=1; i<=n; ++i)
 	{
 		if(a[i]&1) if(A==0) A=i;
 		else B=i;
 	}
 	for(int i=1; i<=n; ++i)
 	{
 		if(b[i]&1) if(C==0) C=i;
 		else D=i;
 	}
 	if(A&&C)
 	{
 		printf("? %d %d %d %d\n",A,C,A,C);
 		fflush(stdout);
 		int res=read();
 		if(res==1)
 		{
 			printf("! %d %d %d %d\n",A,C,B,D);
 			return 0;
 		}
 		else
 		{
 			printf("! %d %d %d %d\n",A,D,B,C);
 			return 0;
 		}
 	}
 	if(A)
 	{
 		int l=1,r=n,ans=1;
 		while(l<=r)
 		{
 			int mid=(l+r)>>1;
 			printf("? %d %d %d %d\n",A,1,A,mid);
 			fflush(stdout);
 			int X=read();
 			if(X&1) ans=mid,r=mid-1;
 			else l=mid+1;
 			
 		}
 		printf("! %d %d %d %d\n",A,ans,B,ans);
 		return 0;
 	}
 	if(C)
 	{
 		int l=1,r=n,ans=1;
 		while(l<=r)
 		{
 			int mid=(l+r)>>1;
 			printf("? %d %d %d %d\n",1,C,mid,C);
 			fflush(stdout);
 			int X=read();
 			if(X&1) ans=mid,r=mid-1;
 			else l=mid+1;
 			
 		}
 		printf("! %d %d %d %d\n",ans,C,ans,D);
 		return 0;
 	}
 	return -1;
}