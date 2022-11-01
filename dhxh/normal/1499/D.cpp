#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e7 + 5;
const int N = 2e7;

int c, d, n, t;

int cnt[maxn];

vector <int> prime;
bool isnp[maxn];

int main(){
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
	
	for(i=2;i<=N;i++){
		if(isnp[i]) continue;
		for(j=i;j<=N;j+=i){
			cnt[j] += 1;
		}
	}
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d%d", &c, &d, &n);
		
		int ans = 0;
		
		for(i=1;i*i<=n;i++){
			if(n % i) continue;
			int p = n / i + d;
			if(p % c == 0){
				p /= c;
				ans += (1 << cnt[p]);
			}
			
			if(i * i == n) continue;
			
			p = i + d;
			if(p % c == 0){
				p /= c;
				ans += (1 << cnt[p]);
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}