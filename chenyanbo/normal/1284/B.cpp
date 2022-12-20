#pragma GCC optimize("Ofast")
#pragma GCC target("avx") 
#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define INF 0x3f3f3f3f
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;
#define lo(x)  ((x)&(-(x)))
#define N 1090009
#define MM 1000001
int f[N],S,n,mi[N],ma[N],fl[N],l,a[N];
long long Ans;
void add(int p)
{
	for(int i=p;i<=MM;i+=lo(i))++f[i];
}
int que(int p)
{
	int s=0;
	for(;p;p-=lo(p))s+=f[p];
	return s;
}

inline void _Sol_()
{
	read(n);
	F(i,1,n){
		read(l); mi[i]=INF;
		F(j,1,l){
			read(a[j]);
			if(a[j]>mi[i])fl[i]=1;
			chmax(ma[i],a[j]);
			chmin(mi[i],a[j]);
		}
		if(!fl[i])add(ma[i]+1);else ++S;
	}
	
	F(i,1,n){
		if(fl[i]){
			Ans+=n;continue;
		}
		Ans+=S;
		Ans+=que(MM)-que(mi[i]+1);
	}
	cout<<Ans;
}

int main()
{
	_Sol_();
}/* 1 1000000*/