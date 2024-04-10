// Problem: A. Regular Bracket Sequences
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1574/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int t,n;
signed main(){
	read(t);
	while(t--){
		read(n);
		if(n==2){
			printf("()()\n(())\n");
			continue;
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=i;j++)putchar('(');
			for(int j=1;j<=i;j++)putchar(')');
			for(int j=i+1;j<=n;j++)putchar('(');
			for(int j=i+1;j<=n;j++)putchar(')');
			puts("");
		}
		while(n--)printf("()");
		puts("");
	}
}