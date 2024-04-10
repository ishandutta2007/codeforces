// Problem: F. BareLee
// Contest: Codeforces - Codeforces Round #652 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1369/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
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
int a[100003],b[100003];
bool Getwin(int x,int y)
//MatrixCascade win win
{if(x>y) return 1;
	if(y&1) return (x&1)^1;
	if(x==y) return 0;
	int g=y>>1,l=g+1,r=y,type=0;
	//type 0  0101
	//type 1  1010
	//type 2  1111
	if(x>=l) return ((r-x)&1)^type;
	while(1)
	{
		int tg=g>>1,tl=tg+1,tr=g,tt;
		if(type==2) tt=0;
		else if(((r-tr*2)&1)^type) 
			tt=(((r-tr)&1)^type);
		else tt=2;
		g=tg,l=tl,r=tr,type=tt;
		if(x>=l) 
		if(type!=2) return ((r-x)&1)^type;
		else return 1;
	}
}
bool Getlose(int x,int y)
//dead_X lose lose
{if(x>y) return 0;
	//if(!(y&1)) return (x&1)^1;
	if(x==y) return 1;
	int g=y>>1,l=g+1,r=y,type=2;
	//type 0  0101
	//type 1  1010
	//type 2  1111
	if(x>=l) return 1;
	while(1)
	{
		int tg=g>>1,tl=tg+1,tr=g,tt;
		if(type==2) tt=0;
		else if(((r-tr*2)&1)^type) 
			tt=(((r-tr)&1)^type);
		else tt=2;
		g=tg,l=tl,r=tr,type=tt;
		// cout<<type<<endl;
		if(x>=l) 
		if(type!=2) return ((r-x)&1)^type;
		else return 1;
	}
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read(),b[i]=read();
	bool Fwin=0,Flose=0,Swin=0,Slose=0;
	for(int i=n; i>=n; --i)
	{
		Fwin=Getwin(a[i],b[i]),Flose=Getlose(a[i],b[i]);
		Swin=Getwin(a[i]+1,b[i])&&Getwin(a[i]<<1,b[i]),
		Slose=Getlose(a[i]+1,b[i])&&Getlose(a[i]<<1,b[i]);
	}
	for(int i=n-1; i>=1; --i)
	{
		bool fwin,flose,swin,slose;
		fwin=Getwin(a[i],b[i]),flose=Getlose(a[i],b[i]);
		swin=Getwin(a[i]+1,b[i])&&Getwin(a[i]<<1,b[i]),
		slose=Getlose(a[i]+1,b[i])&&Getlose(a[i]<<1,b[i]);
		bool tfw,tfl,tsw,tsl;
		tfw=(fwin&&Swin)||(flose&&Fwin)||(Fwin&&Swin),
		tfl=(fwin&&Slose)||(flose&&Flose)||(Flose&&Slose),
		tsw=(swin&&Swin)||(slose&&Fwin)||(Fwin&&Swin),
		tsl=(swin&&Slose)||(slose&&Flose)||(Flose&&Slose),
		Fwin=tfw,Flose=tfl,Swin=tsw,Slose=tsl;
	}
	printf("%d %d\n",(signed)Fwin,(signed)Flose);
    return 0;
}