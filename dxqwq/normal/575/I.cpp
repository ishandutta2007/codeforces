// Problem: I. Robots protection
// Contest: Codeforces - Bubble Cup 8 - Finals [Online Mirror]
// URL: https://codeforces.com/problemset/problem/575/I
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct node{int x,y,z;};
node v1[100003],v2[100003],v3[100003],v4[100003]; 
int c1,c2,c3,c4;
void R(node&t)
{
	t.x=read(),t.y=read(),t.z=read();
}
signed main()
{
	read();
	for(int T=read();T--;)
	{
		if(read()==1)
		{
			int op=read();
			if(op==1) R(v1[++c1]),v1[c1].z=v1[c1].x+v1[c1].y+v1[c1].z;
			else if(op==2) R(v2[++c2]),v2[c2].z=v2[c2].x-v2[c2].y+v2[c2].z;
			else if(op==3) R(v3[++c3]),v3[c3].z=v3[c3].y-v3[c3].x+v3[c3].z;
			else R(v4[++c4]),v4[c4].z=v4[c4].x+v4[c4].y-v4[c4].z;
		}
		else
		{
			int x=read(),y=read(),ans=0;
			//++,+-,-+,--
			for(int i=1; i<=c1; ++i) 
				(x>=v1[i].x&&y>=v1[i].y&&x+y<=v1[i].z)&&(++ans);
			for(int i=1; i<=c2; ++i) 
				(x>=v2[i].x&&y<=v2[i].y&&x-y<=v2[i].z)&&(++ans);
			for(int i=1; i<=c3; ++i) 
				(x<=v3[i].x&&y>=v3[i].y&&y-x<=v3[i].z)&&(++ans);
			for(int i=1; i<=c4; ++i) 
				(x<=v4[i].x&&y<=v4[i].y&&x+y>=v4[i].z)&&(++ans);
			printf("%d\n",ans);
		}
	}
	return 0;
}