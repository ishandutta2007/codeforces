#include<bits/stdc++.h>
using namespace std;

int phi[100001];
vector<int> v[100001];
int a[100001],cnt[100001];
const int MOD=1000000007;
int main() {
	iota(phi,phi+100001,0);
	for(int i=1;i<=100000;i++){
		v[i].push_back(i);
		for(int j=i+i;j<=100000;j+=i){
			phi[j]-=phi[i];
			v[j].push_back(i);
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long t=0;
		for(int j=i;j<=n;j+=i){
			for(int x:v[a[j]]){
				t=(t+phi[x]*cnt[x])%MOD;
				cnt[x]++;
			}
		}
		ans=(ans+t*phi[i])%MOD;
		for(int j=i;j<=n;j+=i){
			for(int x:v[a[j]])cnt[x]--;
		}
	}
	ans=(ans*2)%MOD;
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*i*a[i])%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}