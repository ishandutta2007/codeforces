// Problem: A. Local Extrema
// Contest: Codeforces - Educational Codeforces Round 32
// URL: https://codeforces.com/contest/888/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[13],b[13];
int A0,A1,B0,B1,P,Q,C0,C1,C;
int check(int x,int y)
{
	bool f=1;
	if(A0<=x&&x<=A1) f=1;
	else f=0;
	if(B0<=y&&y<=B1) f=f;
	else f=0;
	if(!f) return 0;
	if(abs(x-P)+abs(y-Q)<=C) return 1;
	return 0;
}
signed main()
{
	for(int i=0; i<8; i++) a[i]=read();
	A0=min(min(a[0],a[2]),min(a[4],a[6]));
	A1=max(max(a[0],a[2]),max(a[4],a[6]));
	B0=min(min(a[1],a[3]),min(a[5],a[7]));
	B1=max(max(a[1],a[3]),max(a[5],a[7]));
	for(int i=0; i<8; i++) b[i]=read();
	P=(b[0]+b[2]+b[4]+b[6])/4;
	Q=(b[1]+b[3]+b[5]+b[7])/4;
	C0=min(min(b[0],b[2]),min(b[4],b[6]));
	C1=max(max(b[0],b[2]),max(b[4],b[6]));
	C=C1-C0;
	C=C/2;
	for(int i=-100; i<=100; i++) for(int j=-100; j<=100; j++) if(check(i,j)) puts("YES"),exit(0);
	
	puts("NO");
	return 0;
}