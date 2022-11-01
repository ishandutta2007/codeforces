#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

long long n, m, t;

struct bt {
	long long tree[maxn];
	
	int lowbit(int x){
		return x & -x;
	}
	
	long long sum(long long p){
		if(p > n)p--;
		long long ret = 0;
		while(p){
			ret += tree[p];
			p -= lowbit(p);
		}
		return ret;
	}
	
	long long update(int p, long long x){
		while(p <= n){
			tree[p] += x;
			p += lowbit(p);
		}
		return 0;
	}
} treea, treeb;

long long a[maxn];
int c[maxn];
int p[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	int i, j;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		c[i] = i;
	}
	
	sort(c + 1, c + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		p[c[i]] = i;
	}
	
	for(i=1;i<=n;i++){
		int l = 0, r = n;
		while(l + 1 < r){
			int mid = (l + r) / 2;
			if(treea.sum(mid) + a[i] > m){
				r = mid;
			}else{
				l = mid;
			}
		}
		if(treea.sum(l + 1) + a[i] <= m)l++;
		cout << i - treeb.sum(l) - 1 << " ";
		treea.update(p[i], a[i]);
		treeb.update(p[i], 1);
	}
	cout << endl;
	
	return 0;
}