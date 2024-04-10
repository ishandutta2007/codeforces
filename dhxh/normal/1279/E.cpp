#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
long long inf = 2e18;

long long t;
long long n;
long long m;

long long fac[maxn];
long long f[maxn];
long long fr[maxn];
bool vis[maxn];
int fa[maxn];

long long mul(long long x, long long y){
	long long ret = x * y;
	if(ret >= inf or ret / x != y) ret = inf;
	return ret;
}

long long calc(long long x){
	if(x == 1) return 1;
	return fac[x - 2];
}

int init(int n){
	for(int i=1;i<=n;i++)fa[i] = i;
	return 0;
}

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

vector <long long> getn(long long x, long long y){
	vector <long long> ret;
	init(x);
	memset(vis, 0, sizeof(vis));
	ret.push_back(x);
	fa[x] = 1;
	vis[x] = true;
	long long z = x - 3;
	
	y++;
	
	for(long long i=1;i<x;i++){
		for(long long j=1;j<=x;j++){
			if(!vis[j] and i == x - 1){
				ret.push_back(j);
				break;
			}
			if(find(i + 1) == find(j) or vis[j]) continue;
			if(z < 0) z = 0;
			if(fac[z] >= y){
				z--;
				ret.push_back(j);
				vis[j] = true;
				fa[find(j)] = find(i + 1);
				break;
			}else{
				y -= fac[z];
			}
		}
	}
	
	return ret;
}

int main(){
	long long i, j;
	long long x, y;
	
	fac[0] = 1;
	for(i=1;i<=50;i++){
		fac[i] = fac[i - 1] * i;
		if(fac[i] >= inf or fac[i] / i != fac[i - 1]){
			fac[i] = inf;
		}
	}
	
	f[0] = 1;
	
	for(i=1;i<=50;i++){
		for(j=0;j<i;j++){
			f[i] = f[i] + mul(f[j], calc(i - j));
			if(f[i] >= inf)f[i] = inf;
		}
	}
	
	scanf("%lld", &t);
	
	while(t--){
		scanf("%lld%lld", &n, &m);
		
		if(m > f[n]){
			printf("-1\n");
			continue;
		}
		
		vector <long long> vec;
		vector <long long> num;
		long long l = 0;
		
		for(i=1;i<=n;i++){
			if(mul(calc(i - l), f[n - i]) >= m){
				vec.push_back(i - l);
				num.push_back((m - 1) / f[n - i]);
				m = (m - 1) % f[n - i] + 1;
				l = i;
			}else{
				m -= mul(calc(i - l), f[n - i]);
			}
		}
		
		long long sum = 0;
		
		for(i=0;i<vec.size();i++){
			x = vec[i];
			y = num[i];
			
			vector <long long> tmp = getn(x, y);
			for(auto y : tmp){
				printf("%lld ", y + sum);
			}
			
			sum += x;
		}
		printf("\n");
	}
	
	return 0;
}