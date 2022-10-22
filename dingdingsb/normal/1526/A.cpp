// Problem: CF1526A Mean Inequality
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1526A
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=60;
int t,n,a[N];
signed main(){
	read(t);while(t--){
		read(n);for(int i=1;i<=2*n;i++)read(a[i]);
		sort(a+1,a+1+2*n);
		for(int i=1;i<=n;i++)write(a[i]),putchar(' '),write(a[i+n]),putchar(' ');
		putchar('\n');
	}
}