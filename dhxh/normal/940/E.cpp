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

int n, m, t;

long long a[maxn];
long long sum[maxn];

priority_queue <pair <long long, int> > pq;

long long f[maxn];

struct que {
	int l, r;
	long long delta;
	long long a[maxn];
	int b[maxn];
	
	int push(long long x, long long y){
		r++;
		a[r] = x - delta;
		b[r] = y;
		
		while(r > l and a[r - 1] >= a[r]){
			a[r - 1] = a[r];
			b[r - 1] = b[r];
			r--;
		}
		
		return 0;
	}
	
	long long front(int x){
		while(x - b[l] >= m){
			l++;
		}
		
		return a[l] + delta;
	}
	
	que(){
		l = 1, r = 0;
	}
} q;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	
	pq.push(make_pair(0, 0));
	
	for(i=1;i<=n;i++){
		q.delta += a[i];
		pq.push(make_pair(-a[i], i));
		f[i] = q.front(i);
		
		while(pq.size() and pq.top().second <= i - m){
			pq.pop();
		}
		
		if(i - m >= 0){
			f[i] = min(f[i], f[i - m] + sum[i] - sum[i - m] + pq.top().first);
		}
		
		q.push(f[i], i);
	}
	
	printf("%lld\n", f[n]);
	
	return 0;
}