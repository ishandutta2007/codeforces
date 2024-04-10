#include <bits/stdc++.h>
#define N 500100
using namespace std;
const int mod=998244353;
int n,k,m,i,j,l[N],r[N],x[N],pos[N],d[N];
long long f[N],ans=1;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
	cin >> n >> k >> m;
	for(i=1;i<=m;i++) cin >> l[i] >> r[i] >> x[i];
	for(i=0;i<k;i++){
		for(j=1;j<=n;j++) d[j]=pos[j]=0;
		for(j=1;j<=m;j++){
			if(x[j]&(1<<i)) d[l[j]]++,d[r[j]+1]--;
			else pos[r[j]]=max(pos[r[j]],l[j]);
		}
		for(j=1;j<=n;j++){
			d[j]+=d[j-1];
			pos[j]=max(pos[j],pos[j-1]);
		}
		int p=0;
		long long res=0,sum=1;
		f[0]=1;
		for(j=1;j<=n;j++){
			if(d[j]) f[j]=0;
			else f[j]=sum;
			while(p<pos[j]){
				sum=(sum-f[p]+mod)%mod;
				f[p]=0;
				p++;
			}
			sum=(sum+f[j])%mod;
		}
		for(j=pos[n];j<=n;j++) res=(res+f[j])%mod;
		ans=ans*res%mod;
	}
	printf("%lld\n",ans);
	return 0;
}