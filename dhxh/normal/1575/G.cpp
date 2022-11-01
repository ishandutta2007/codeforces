#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const int maxn = N + 5;
const int mod = 1e9 + 7;

int n, m;

bool isnp[maxn];
vector <int> prime;
int u[maxn];
vector <int> fac[maxn];
vector <int> vec[maxn];

int a[maxn];

long long f[maxn];
long long g[maxn];
long long cnt[maxn];

void init(){
	int i, j;
	/*u[1] = 1;
	for(i=2;i<=N;i++){
		if(!isnp[i]){
			u[i] = -1;
			prime.push_back(i);
		}
		for(auto j : prime){
			if(i * j > N) break;
			isnp[i * j] = true;
			u[i * j] = u[i] * u[j];
			if(i % j == 0) break;
		}
	}*/

	for(i=1;i<=N;i++){
		for(j=i;j<=N;j+=i){
			fac[j].push_back(i);
		}
		//reverse(fac[i].begin(), fac[i].end());
	}
}

int main(){
	int i, j;
	init();

	scanf("%d", &n);

	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		for(auto x : fac[a[i]]){
			vec[x].push_back(i);
		}
	}

	long long ans = 0;

	for(int x=1;x<=N;x++){
		vector <int> p;
		for(auto i : vec[x]){
			for(auto y : fac[i]){
				p.push_back(y);
				cnt[y]++;
			}
		}
		if(p.size() < n / 16){
			sort(p.begin(), p.end());
			int sz = unique(p.begin(), p.end()) - p.begin();
			p.resize(sz);
			reverse(p.begin(), p.end());
			for(auto i : p){
				cnt[i] = cnt[i] * cnt[i];
			}

			for(auto i : p){
				f[x] = (f[x] + i * cnt[i]) % mod;
				for(auto j : fac[i]){
					if(i == j) continue;
					cnt[j] -= cnt[i];
				}
				cnt[i] = 0;
			}
		}else{
			for(i=1;i<=n;i++){
				cnt[i] = cnt[i] * cnt[i];
			}
			for(i=n;i>0;i--){
				for(j=2*i;j<=n;j+=i){
					cnt[i] -= cnt[j];
				}
				f[x] = (f[x] + i * cnt[i]) % mod;
			}
			for(i=1;i<=n;i++) cnt[i] = 0;
		}

	}

	for(i=N;i>0;i--){
		for(j=2*i;j<=N;j+=i){
			f[i] = (f[i] - f[j] + mod) % mod;
		}
		ans = (ans + f[i] * i) % mod;
	}
	ans = (ans + mod) % mod;
	printf("%lld\n", ans);

	return 0;
}