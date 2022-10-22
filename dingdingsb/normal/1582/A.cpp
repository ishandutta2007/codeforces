// Problem: A. Luntik and Concerts
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/A
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
int t,a,b,c;
signed main(){
	read(t);
	while(t--){
		read(a,b,c);
		if(a%2&&b%2&&c%2)puts("0");
		else if(a%2==0&&b%2==0&&c%2==0)puts("0");
		else{
			c%=2;int tmp=0;
			if(c)tmp=3;
			if(b)tmp-=2;if(tmp<0)tmp=-tmp;b--;
			if(b)tmp-=2;if(tmp<0)tmp=-tmp;
			if(a>tmp)a-=tmp,write(a%2),pc('\n');
			else write(tmp-a),pc('\n');
		}
	}
}