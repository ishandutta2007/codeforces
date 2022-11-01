#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

long long ans = 0;

struct ex {
	long long x;
	long long y;
	long long a;
};

ex p[maxn];

struct queue {
	long long k[maxn];
	long long b[maxn];
	int l, r;
	
	double getp(long long ka, long long ba, long long kb, long long bb){
		return (double)(bb - ba) / (double)(ka - kb);
	}
	
	int push(long long kk, long long bb){
		while(r - l + 1 > 1 and getp(k[r], b[r], kk, bb) > getp(k[r - 1], b[r - 1], k[r], b[r])){
			r--;
		}
		
		r++;
		k[r] = kk;
		b[r] = bb;
		
		return 0;
	}
	
	int pop(long long x){
		while(r - l + 1 > 1 and k[l] * x + b[l] < k[l + 1] * x + b[l + 1]){
			l++;
		}
		
		return 0;
	}
	
	long long front(long long x){
		if(r - l + 1 <= 0){
			return 0;
		}
		return k[l] * x + b[l];
	}
	
	queue(){
		r = 0, l = 1;
	}
};

queue q;

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

bool cmp(ex x, ex y){
	return x.y > y.y;
}

int main(){
	int i, j;
	long long tmp;
	
	n = read();
	
	for(i=1;i<=n;i++){
		p[i].x = read();
		p[i].y = read();
		p[i].a = read();
	}
	
	sort(p + 1, p + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		q.pop(p[i].y);
		tmp = q.front(p[i].y) + p[i].x * p[i].y - p[i].a;
		tmp = max(tmp, p[i].x * p[i].y - p[i].a);
		ans = max(ans, tmp);
		q.push(-p[i].x, tmp);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}