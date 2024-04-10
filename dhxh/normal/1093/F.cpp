#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e5 + 5;

long long mod = 998244353;

int n, m, t, k;

int a[maxn];

struct dp {
	queue <long long> q;
	long long sum;
	
	int push(long long x){
		sum = (sum + x) % mod;
		q.push(x);
		
		if(q.size() >= m){
			sum = (sum - q.front() + mod) % mod;
			q.pop();
		}
		
		return 0;
	}
	
	int clear(){
		int i, j;
		sum = 0;
		queue <long long> empty;
		swap(q, empty);
		
		return 0;
	}
	
	dp(){sum = 0;}
};

dp f[5];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long sum;
	long long ans = 0;
	int x, y = -1;
	queue <int> q;
	
	n = read();
	k = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		if(a[i] != -1){
			q.push(a[i]);
		}
	}
	
	if(a[1] == -1){
		f[0].push(k);
		f[1].push(1);
	}else{
		f[0].push(1);
		x = q.front();
		q.pop();
		
		if(q.size() >= 1){
			if(q.front() == x){
				f[1].push(1);
			}else{
				f[1].clear();
			}
		}
	}
	
	for(i=2;i<=n;i++){
		sum = f[0].sum;
		
		if(a[i] == -1){
			f[0].push(sum * (long long)(k - 1) % mod);
			f[1].push((sum - f[1].sum + mod) % mod);
		}else{
			x = q.front();
			q.pop();
			
			f[1].push((sum - f[1].sum + mod) % mod);
			f[0] = f[1];
			
			if(q.size() >= 1){
				if(q.front() != x){
					f[1].clear();
				}
			}
		}
	}
	
	ans = f[0].sum;
	
	printf("%lld\n", ans);
	
	return 0;
}