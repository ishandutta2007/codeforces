#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, p, k;
ll ans;
map<int,int> f;
int main() {
	scanf("%d%d%d", &n, &p, &k);
	for(int i=1; i<=n; ++i){
		int x;
		scanf("%d", &x);
		ans+=f[((ll)x*x%p*x-k+p)%p*x%p]++;
	}
	return printf("%lld", ans), 0;
}