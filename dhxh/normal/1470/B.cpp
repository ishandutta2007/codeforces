#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int N = 1e6;

int a[maxn];

int n, m, t;

bool isnp[maxn];
vector <int> prime;

int cnt[maxn];
bool vis[maxn];

void init(){
	int i, j;
	
	for(i=2;i<=N;i++){
		if(!isnp[i]){
			prime.push_back(i);
		}
		
		for(auto j : prime){
			if(i * j > N) break;
			isnp[i * j] = true;
			if(i % j == 0) break;
		}
	}
}

int main(){
	init();
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			
			int x = a[i];
			int ans = 1;
			
			for(auto j : prime){
				if(j * j > a[i]) break;
				int z = 0;
				while(x % j == 0){
					x /= j;
					z ^= 1;
				}
				if(z) ans *= j;
			}
			if(x > 1) ans *= x;
			a[i] = ans;
			cnt[ans]++;
		}
		
		int ansa = 0, ansb = cnt[1];
		vis[1] = true;
		for(i=1;i<=n;i++){
			ansa = max(ansa, cnt[a[i]]);
		}
		
		for(i=1;i<=n;i++){
			if(vis[a[i]]) continue;
			if((cnt[a[i]] & 1) == 0){
				ansb += cnt[a[i]];
				vis[a[i]] = true;
			}
		}
		
		ansb = max(ansa, ansb);
		
		int q;
		scanf("%d", &q);
		
		while(q--){
			long long x;
			scanf("%lld", &x);
			
			if(x == 0){
				printf("%d\n", ansa);
			}else{
				printf("%d\n", ansb);
			}
		}
		
		for(i=1;i<=n;i++){
			cnt[a[i]] = 0;
			vis[a[i]] = false;
		}
		vis[1] = false;
	}
	
	return 0;
}