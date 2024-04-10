#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

int a[maxn];

void solve(){
	int i, j;
	long long ans = 0;
	vector <pair <int, int> > vec;
	
	for(i=1;i<=n;i++) a[i] = i;
	
	if(n & 1){
		for(i=1;i<n/2;i++){
			vec.push_back({1, n - i});
			vec.push_back({n, 1 + i});
			ans += 2ll * (n - i - 1) * (n - i - 1);
		}
		vec.push_back({1, n});
		vec.push_back({1, n / 2 + 1});
		ans += 1ll * (n - 1) * (n - 1);
		ans += 1ll * (n / 2) * (n / 2); 
	}else{
		for(i=1;i<n/2;i++){
			vec.push_back({1, n - i});
			vec.push_back({n, 1 + i});
			ans += 2ll * (n - i - 1) * (n - i - 1);
		}
		vec.push_back({1, n});
		ans += 1ll * (n - 1) * (n - 1);
	}
	
	for(i=(int)vec.size()-1;i>=0;i--){
		auto [x, y] = vec[i];
		swap(a[x], a[y]);
		if(a[x] == y) swap(vec[i].first, vec[i].second);
	}
	printf("%lld\n", ans);
	for(i=1;i<=n;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("%d\n", vec.size());
	for(auto [x, y] : vec){
		printf("%d %d\n", x, y);
	}
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		solve();
	}
	
	return 0;
}