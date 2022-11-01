#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 233, base = 2333333, P1 = 1000000009, P2 = 998244853;
int n, k, cnt, a[N], b[N];
ll ans;
map<ll,int> f;
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i){
		int x, cnt=0;
		scanf("%d", &x);
		for(int j=2; j*j<=x; ++j) if(x%j==0){
			a[++cnt]=j, b[cnt]=1, x/=j;
			while(x%j==0) ++b[cnt], x/=j;
		}
		if(x>1) a[++cnt]=x, b[cnt]=1;
		int t1=0, t2=0;
		for(int j=1; j<=cnt; ++j) if(b[j]%k){
			t1=((ll)t1*base+a[j])%P1;
			t1=((ll)t1*base+b[j]%k)%P1;
			t2=((ll)t2*base+a[j])%P2;
			t2=((ll)t2*base+b[j]%k)%P2;
		}
		ans+=f[t1*1000000000ll+t2];
		t1=0, t2=0;
		for(int j=1; j<=cnt; ++j) if((k-b[j]%k)%k){
			t1=((ll)t1*base+a[j])%P1;
			t1=((ll)t1*base+(k-b[j]%k)%k)%P1;
			t2=((ll)t2*base+a[j])%P2;
			t2=((ll)t2*base+(k-b[j]%k)%k)%P2;
		}
		++f[t1*1000000000ll+t2];
	}
	printf("%lld\n", ans);
	return 0;
}