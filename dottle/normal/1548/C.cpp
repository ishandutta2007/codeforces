#include<bits/stdc++.h>
#define int long long
const int N=4000060;
using namespace std;

int iv[N],jc[N],ans[N],res[N];
int n,p=1e9+7,x,q;

int C(int n,int m){
	return jc[n]*iv[m]%p*iv[n-m]%p;
}

signed main(){
	scanf("%lld%lld",&n,&q),jc[0]=iv[0]=iv[1]=1;
	for(int i=2;i<=n*3+3;i++)
		iv[i]=p-(p/i)*iv[p%i]%p;
	for(int i=1;i<=n*3+3;i++)
		iv[i]=iv[i-1]*iv[i]%p,jc[i]=jc[i-1]*i%p;
	for(int i=0;i<=3*n+3;i++)
		ans[i]=C(3*n+3,i);
	ans[0]--,ans[1]-=3,ans[2]-=3,ans[3]--;
	for(int i=3*n+3;i>=3;i--){
		int x=ans[i];res[i-3]=(x%p+p)%p;
		ans[i]-=x,ans[i-1]-=3*x,ans[i-2]-=3*x;
		ans[i-1]%=p,ans[i-2]%=p,ans[i-3]%=p;
	}
	for(int i=1;i<=q;i++)scanf("%lld",&x),printf("%lld\n",res[x]);
	return 0;
}