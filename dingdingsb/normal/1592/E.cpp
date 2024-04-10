// Problem: CF1592E Bored Bakry
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1592E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
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
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e6+100,B=20;
int n,a[N],sum[N],c[N],lst[N];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	int ans=0;
	for(int j=B;~j;j--){
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+(a[i]>>j&1);
		for(int i=1;i<=n;i++)
			c[i]=c[i-1]^(a[i]>>j<<j);
		memset(lst,-1,sizeof lst);lst[0]=0;
		for(int i=1;i<=n;i++){
			if(lst[c[i]]!=-1){
				if(sum[i]-sum[lst[c[i]]]==i-lst[c[i]])chkmx(ans,i-lst[c[i]]);
				else lst[c[i]]=i;
			}else lst[c[i]]=i;
		}
	}
	write(ans);
}