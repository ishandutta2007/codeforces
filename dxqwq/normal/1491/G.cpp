// Problem: G. Switch and Flip
// Contest: Codeforces - Codeforces Global Round 13
// URL: https://codeforces.com/contest/1491/problem/G
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
int X[1000003],Y[1000003],C;
int p[1000003];
void print(int x,int y)
{
	X[++C]=min(x,y),Y[C]=max(x,y),
	swap(p[x],p[y]),
	p[x]=-p[x],p[y]=-p[y];
}
void flush()
{
	printf("%d\n",C);
	for(int i=1; i<=C; ++i) printf("%d %d\n",X[i],Y[i]);
	return ;
}
void check(int n)
{
	for(int i=1; i<=n; ++i) cerr<<p[i]<<" ";
	return ;
}
bool f[1000003],vis[1000003];
int h[1000003],sz[1000003],c;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) p[i]=read();
	for(int i=1; i<=n; ++i) if(!vis[i]&&(p[i]!=i))
	{
		int id=i,cnt=0;
		while(!vis[id]) vis[id]=1,++cnt,id=p[id];
		h[++c]=id,sz[c]=cnt;
	}
	while(c>=2)
	{
		int A=h[c],B=h[c-1];
		print(A,B);
		while(abs(p[A])!=B) print(A,abs(p[A]));
		while(abs(p[B])!=A) print(B,abs(p[B]));
		print(A,B);
		c-=2;
	}
	//1 2
	//-3 -4 2 1
	//-2 -4 3 1
	//-2 -1 3 4
	if(c)
	{
		if(sz[c]==2)
		{
			for(int i=1; i<=n; ++i) if(p[i]==i)
			{
				int A=i,B=h[1],C=p[B];
				print(A,B);
				print(A,C);
				print(A,B);
				break;
			}	
			//id  1  2  3
			//    1  3  2
			//   -3 -1  2
			//   -2 -1  3
			//    1  2  3
		}
		else
		{
			int A=h[1],B=p[A],C=p[B];
			print(A,B);
			print(B,C);
			while(abs(p[A])!=B) print(A,abs(p[A]));
			while(abs(p[B])!=A) print(B,abs(p[B]));
			print(A,B);
			//id  1  2  3
			//    2  3  1
			//   -3 -2  1
			//   -3 -1  2
		}
	}
#ifdef LOCAL
	check(n);
#endif
	flush();
	return 0;
}