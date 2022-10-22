// Problem: CF1545A AquaMoon and Strange Sort
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1545A
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
const int N=1e5+100;
int t,n,a[N];
int sum1[N],sum2[N];
signed main(){
	read(t);
	while(t--){
		memset(sum1,0,sizeof sum1);
		memset(sum2,0,sizeof sum2);
		read(n);
		for(int i=1;i<=n;i++)read(a[i]);
		for(int i=1;i<=n;i+=2)sum1[a[i]]++;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i+=2)sum2[a[i]]++;
		for(int i=1;i<N;i++)if(sum1[i]^sum2[i]){
			puts("NO");
			goto loop;
		}
		puts("YES");
		loop:;
	}
}