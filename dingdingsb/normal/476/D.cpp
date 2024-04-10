// Problem: CF476D Dreamoon and Sets
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF476D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
template<typename T ,typename ...Arg>inline void write(T x,Arg ...args){write(x);putchar(' ');write(args...);}
//#define int long long
typedef long long ll;
int n,k;
signed main(){
	read(n,k);
	write((6*n-1)*k);putchar('\n');
	for(int i=0;i<n;i++)
		write((6*i+1)*k,(6*i+2)*k,(6*i+3)*k,(6*i+5)*k),putchar('\n');
}