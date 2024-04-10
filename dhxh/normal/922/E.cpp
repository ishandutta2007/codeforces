#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 5;

long long n, w, b, m;

long long a[maxn];
long long c[maxn];

long long f[maxn];
bool vis[maxn];

struct queue {
	long long a[maxn];
	int b[maxn];
	long long delta;
	int l, r;
	
	int push(long long x, int y){
		r++;
		a[r] = x - delta;
		b[r] = y;
		
		while(r - l + 1 > 1 and a[r] > a[r - 1]){
			a[r - 1] = a[r];
			b[r - 1] = b[r];
			r--;
		}
		
		return 0;
	}
	
	long long top(int x){
		while(x <= b[l]){
			l++;
		}
		
		return a[l] + delta;
	}
	
	int init(){
		delta = 0;
		l = 1, r = 0;
	}
	
} q;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	long long x = 0;
	
	n = read();
	w = read();
	b = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		x += a[i];
	}
	
	for(i=1;i<=n;i++){
		c[i] = read();
	}
	
	f[0] = w;
	vis[0] = true;
	
	for(i=1;i<=n;i++){
		j = x;
		while(!vis[j - a[i]]){
			j--;
		}
		
		q.init();
		
		for(k=j-1;k>=j-a[i];k--){
			if(vis[k]){
				q.push(f[k] - c[i] * (j - k), k);
			}
		}
		
		for(;j>0;j--){
			if(q.top(j) >= 0){
				f[j] = max(f[j], q.top(j));
				vis[j] = true;
			}
			
			k = j - a[i] - 1;
			q.delta += c[i];
			if(k >= 0){
				q.push(f[k] - c[i] * a[i], k);
			}
		}
		
		for(j=x;j>=0;j--){
			if(vis[j]){
				f[j] = min(w + b * j, f[j] + m);
			}
		}
	}
	
	for(j=x;j>=0;j--){
		if(vis[j]){
			printf("%d\n", j);
			break;
		}
	}
	
	return 0;
}