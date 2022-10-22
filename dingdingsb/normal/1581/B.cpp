// Problem: B. Diameter of Graph
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.ml/contest/1581/problem/B
// Memory Limit: 256 MB
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
#define int long long
typedef long long ll;
int t,n,m,k;
signed main(){
	read(t);
	while(t--){
		read(n,m,k);
		if(m<n-1)puts("No");
		else if(m>n*(n-1)/2)puts("No");
		else{
			int mx;
			if(n==1)mx=0;
			else if(m>=n*(n-1)/2)mx=1;
			else mx=2;
			if(mx<k-1)puts("Yes");
			else puts("No");
		}
	}
}