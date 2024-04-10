#include<cstdio>
#define int long long
const int N=2e5+3;
int n,b[N],a[N],bt[N];
inline void Add(int k,int a){for(;k&&k<=n;k+=k&-k)bt[k]+=a;}
inline int Sum(int k){int s=0;for(;k;k-=k&-k)s+=bt[k];return s;}
signed main(){
	int l,r,m;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
	  scanf("%lld",&b[i]);
	  bt[i]+=i;
	  if(i+(i&-i)<=n)bt[i+(i&-i)]+=bt[i];
	}
	for(int i=n;i;i--){
	  l=0,r=n;
	  for(;l<r;)m=l+r>>1,Sum(m)>b[i]?r=m:l=m+1;
	  a[i]=l;Add(l,-l);
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}