#include<bits/stdc++.h>
typedef long long ll;
const int N=5e5+3,K=60,M=1e9+7;
int n,c[K],s_and,s_or,s;ll a[N];
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	s=0;
	for(int j=0;j<K;j++)c[j]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%lld",a+i);
	  for(int j=0;j<K;j++)c[j]+=a[i]>>j&1;
	}
	for(int i=1;i<=n;i++){
	  s_and=s_or=0;
	  for(int j=0;j<K;j++)
		if(a[i]>>j&1){
		  s_and=(s_and+(1ll<<j)%M*c[j])%M;
		  s_or=(s_or+(1ll<<j)%M*n)%M;
		}
		else{
		  s_or=(s_or+(1ll<<j)%M*c[j])%M;
		}
	  s=(s+(ll)s_and*s_or)%M;
	}
	printf("%d\n",s);
	}return 0;
}