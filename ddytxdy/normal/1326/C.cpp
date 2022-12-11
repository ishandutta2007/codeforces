#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50,mod=998244353;
int n,k,a[N],p[N],st[N],ans2=1;LL ans1;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]]=i;
	for(int i=1;i<=k;i++)st[i]=p[n-i+1],ans1+=n-i+1;
	sort(st+1,st+k+1);
	for(int i=1;i<k;i++)ans2=1ll*ans2*(st[i+1]-st[i])%mod;
	cout<<ans1<<" "<<ans2;
	return 0;
}