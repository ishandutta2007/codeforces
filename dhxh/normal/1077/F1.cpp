#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 205;

int n, m, t, k;

struct queue {
	long long a[maxn];
	int b[maxn];
	int l, r;
	
	int push(long long x, int y){
		r++;
		a[r] = x;
		b[r] = y;
		
		if(b[r] - b[l] + 1 > k){
			l++;
		}
		
		while(r - l + 1 > 1 and a[r] > a[r - 1]){
			a[r - 1] = a[r];
			b[r - 1] = b[r];
			r--;
		}
		
		return 0;
	}
	
	long long front(){
		return a[l];
	}
	
	queue(){
		l = 1, r = 0;
	}
};

queue q[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long x, y;
	
	n = read();
	k = read();
	m = read();
	
	q[0].push(0, 0);
	
	for(i=1;i<=m;i++){
		q[i].push(-1, 0);
	}
	
	for(i=1;i<=n;i++){
		x = read();
		for(j=m;j>0;j--){
			if(q[j - 1].front() == -1){
				q[j].push(-1, i);
			}else{
				q[j].push(q[j - 1].front() + x, i);
			}
		}
		q[0].push(-1, i);
	}
	
	printf("%lld\n", q[m].front());
	
	return 0;
}