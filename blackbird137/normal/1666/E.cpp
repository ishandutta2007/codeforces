//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int l,n,a[100002],x;
inline bool check(int x){
	int now=a[1];
	F(i,1,n){
		if(now+a[i+1]-a[i]<x)return false;
		now=max(0,a[i+1]-a[i]-(x-now));
		now=min(now,a[i+1]-a[i]);
	}
	return true;
}
int f[100002],g[100002];
inline bool check2(int y){
	int now=a[1];
	F(i,1,n){//cerr<<y<<" "<<i<<" "<<now<<endl;
		if(now+a[i+1]-a[i]<x)return false;
		if(now>y)return false;
		now=max(f[i+1],a[i+1]-a[i]-y+now);
		
	}
	return now==0;
}
inline bool getans(int y){
//	cerr<<x<<" "<<y<<endl;F(i,1,n)cerr<<f[i]<<endl;
	int now=a[1];
	F(i,1,n){//cerr<<y<<" "<<i<<" "<<now<<endl;
		write(a[i]-now,' ');
		if(now+a[i+1]-a[i]<x)return false;
		if(now>y)return false;
		now=max(f[i+1],a[i+1]-a[i]-y+now);
		write(a[i+1]-now,'\n');
	}
	return now==0;
}
inline void solve(int X){
	x=X;
	UF(i,n,1){
		f[i]=max(f[i+1]-a[i+1]+a[i]+x,x-a[i+1]+a[i]);
		f[i]=max(f[i],0);
	}
	int r=l;
	int l=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(check2(mid))r=mid;
		else l=mid+1;
	}
	getans(l);
}
int main() {
	cin>>l>>n;
	F(i,1,n)read(a[i]);
	a[n+1]=l;
	int x=0,y=l;
	while(x<y){
		int mid=(x+y+1)>>1;
		if(check(mid))x=mid;
		else y=mid-1;
	}
	solve(x);
	return 0;
}
/*
10 4
5 6 7 8
*/