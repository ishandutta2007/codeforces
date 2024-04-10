#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

long long mod = 998244353;

long long n, m;

long long a[maxn];
bool vis[maxn];

struct btree {
	long long tree[maxn];
	long long t;
	
	long long lowbit(long long x){
		return x & -x;
	}
	
	long long sum(long long x){
		long long ret = 0;
		
		while(x){
			ret += tree[x];
			x -= lowbit(x);
		}
		
		return ret;
	}
	
	long long update(long long x, long long p){
		while(x <= n){
			tree[x] += p;
			x += lowbit(x);
		}
		return 0;
	}
};

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

long long qpow(long long b, long long x){
	long long ret = 1;
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		
		b = b * b % mod;
		x >>= 1;
	}
	
	return ret;
}

btree treea;
btree treeb;

vector <long long> vec;
vector <long long> b;

long long query_min(long long x){
	long long l = 0, r = (long long)b.size() - 1;
	long long mid;
	
	if(b.size() == 0 or b[0] > x){
		return 0;
	}
	
	while(l + 1 < r){
		mid = (l + r) / 2;
		if(b[mid] < x){
			l = mid;
		}else{
			r = mid;
		}
	}
	
	if(b[r] < x){
		l = r;
	}
	
	return l + 1;
}

int main(){
	long long i, j;
	long long ans = 0;
	long long x = 0, y = 0, ret = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(a[i] != -1){
			vec.push_back(a[i]);
			vis[a[i]] = true;
		}
	}
	
	for(i=(long long)vec.size()-1;i>=0;i--){
		ans = (ans + treea.sum(vec[i])) % mod;
		treea.update(vec[i], 1);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			b.push_back(i);
		}
	}
	
	for(i=1;i<=n;i++){
		if(a[i] == -1){
			y++;
		}else{
			x = ((long long)b.size() - query_min(a[i])) % mod;
			ret = (ret + x * y % mod) % mod;
		}
	}
	
	y = 0, x = 0;
	
	for(i=n;i>0;i--){
		if(a[i] == -1){
			y++;
		}else{
			x = (query_min(a[i])) % mod;
			ret = (ret + x * y % mod) % mod;
		}
	}
	
	y = (long long)b.size() * ((long long)b.size() - 1) % mod * qpow(4, mod - 2) % mod;
	
	ans = (ans + y + ret * qpow((long long)b.size(), mod - 2) % mod) % mod;
	
	printf("%lld\n", ans);
	
	return 0;
}