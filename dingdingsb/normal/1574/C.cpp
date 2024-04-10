// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1574/problem/C
// Memory Limit: 256 MB
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
#define int long long
typedef long long ll;
const int N=2e5+100;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,a[N],m,x,y,sum;
signed main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	read(m);
	while(m--){
		read(x,y);
		int A=lower_bound(a+1,a+1+n,x)-a;
		int B=upper_bound(a+1,a+1+n,sum-y)-a-1;
		if(B<A){
			int res=inf;
			if(B)chkmn(res,x-a[B]);
			if(B+1<=A-1)chkmn(res,x+y-sum);
			if(A!=n+1)chkmn(res,y-sum+a[A]);
			write(res);putchar('\n');
		}else puts("0");
	}
}