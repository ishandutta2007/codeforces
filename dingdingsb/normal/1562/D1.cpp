// Problem: D1. Two Hundred Twenty One (easy version)
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/D1
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
const int N=4e5+100;
int t,n,q,s[N];char str[N];
signed main(){
	read(t);while(t--){
		read(n,q);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++){
			int v=str[i]=='+'?1:-1;
			if(i&1)v=-v;s[i]=s[i-1]+v;
		}
		while(q--){
			int l,r;read(l,r);
			if(s[r]-s[l-1]==0)puts("0");
			else if((s[r]-s[l-1])%2)puts("1");
			else puts("2");
		}
	}
}