#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;


int phi[1000005], vis[1000005], prim[1000005];
vector<int> V[1000005];
int cnt = 0;
void get(int maxn) {
	phi[1]=1;
	for(int i=2; i<=maxn; i++) {
		if(!vis[i]) {
			prim[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1; j<=cnt&&prim[j]*i<=maxn; j++) {
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) {
				phi[i*prim[j]]=phi[i]*prim[j];
				break;
			} else phi[i*prim[j]]=phi[i]*(prim[j]-1);
		}
	}
	
	for(int i=1;i<=maxn;i++) {
		for(int j=i;j<=maxn;j+=i) {
			V[j].push_back(i);
		}
	}
	
}


int a[1000005];

int cur[1000005];

signed main() {
	get(200001);
	
	int n;
	cin >> n;
	
		
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	
	int ans = 0;
	
	for(int i=1;i<=n;i++) {
		int tmp = 0;
		for(int j=1;j*i<=n;j++) {
			for(int k=0;k<V[a[i*j]].size();k++) {
				int tmpp = V[a[i*j]][k];
				cur[tmpp] += phi[tmpp];
				cur[tmpp] %= mod;
				tmp += cur[tmpp];
				tmp %= mod;
			}
		}
		
		for(int j=1;j*i<=n;j++) {
			for(int k=0;k<V[a[i*j]].size();k++) {
				int tmpp = V[a[i*j]][k];
				cur[tmpp] -= phi[tmpp];
				cur[tmpp] %= mod;
				cur[tmpp] += mod;
				cur[tmpp] %= mod;
			}
		}
		
		ans += 1ll*phi[i]*tmp%mod;
		ans %= mod;
		
	}
	
	ans = 1ll*ans*2%mod;
	for(int i=1;i<=n;i++) {
		ans -= 1ll*i*a[i]%mod;
		ans %= mod;
		ans += mod;
		ans %= mod;
	}
	cout << ans <<endl;
	

}