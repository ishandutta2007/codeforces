// Problem: D. Diane
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/D
// Memory Limit: 256 MB
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
//#define int long long
typedef long long ll;
int t,n;
signed main(){
	read(t);while(t--){
		read(n);
		if(n==1)puts("a");
		else if(n%2==0){
			for(int i=1;i<=n/2;i++)putchar('a');
			putchar('b');
			for(int i=1;i<n/2;i++)putchar('a');
			putchar('\n');
		}else{
			for(int i=1;i<=n/2;i++)putchar('a');
			putchar('b');putchar('c');
			for(int i=1;i<n/2;i++)putchar('a');
			putchar('\n');
		}
	}
	return 0;
	cout<<"ccfn***";
}