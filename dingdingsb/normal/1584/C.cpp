//

// Problem: A. Two Arrays
// Contest: Codeforces - Codeforces Round #755 (Div. 1, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.ml/contest/1588/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e2+10;
int t,n,a[N],b[N];
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i++)read(b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]&&a[i]+1!=b[i])
				flag=0;
		if(flag)puts("YES");else puts("NO");
	}
}