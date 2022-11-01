#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int N = 1e5;

int n;

vector <int> d[maxn];
int u[maxn];
vector <int> prime;
bool isnp[maxn];

int cnt[maxn];

vector <int> vec[maxn];
int a[maxn];
long long ans = 0;

void init(){
	int i, j;
	
	for(i=1;i<=N;i++){
		for(j=i;j<=N;j+=i){
			d[j].push_back(i);
		}
	}
	
	u[1] = 1;
	for(i=2;i<=N;i++){
		if(!isnp[i]){
			u[i] = -1;
			prime.push_back(i);
		}
		
		for(auto j : prime){
			if(i * j > N) break;
			isnp[i * j] = true;
			if(i % j == 0){
				u[i * j] = 0;
				break;
			}else{
				u[i * j] = -u[i];
			}
		}
	}
}

int count(int x){
	int ret = 0;
	for(auto i : d[x]){
		ret += u[i] * cnt[i];
	}
	return ret;
}

void solve(int p){
	int i, j;
	stack <int> s;
	for(auto x : vec[p]){
		int c = count(x);
		
		while(c){
			i = s.top();
			s.pop();
			if(__gcd(i, x) == 1){
				ans = max(ans, 1ll * p * i * x);
				c--;
			}
			for(auto j : d[i]) cnt[j]--;
		}
		
		s.push(x);
		for(auto i : d[x]) cnt[i]++;
	}
	
	while(s.size()){
		i = s.top();
		s.pop();
		for(auto j : d[i]) cnt[j]--;
	}
}

int main(){
	int i, j;
	int x, y;
	init();
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		a[x]++;
		ans = max(ans, 1ll * x);
	}
	
	for(i=1;i<=N;i++){
		if(!a[i]) continue;
		for(auto x : d[i]){
			vec[x].push_back(i / x);
		}
	}
	
	for(i=1;i<=N;i++){
		if(!vec[i].size()) continue;
		sort(vec[i].begin(), vec[i].end());
		reverse(vec[i].begin(), vec[i].end());
		solve(i);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}