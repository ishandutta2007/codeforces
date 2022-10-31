#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

long long a[maxn];
long long b[maxn];

map <long long, int> sa;
map <long long, int> sb;

int ans = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	long long i, j;
	
	n = read();
	read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
	}
	
	m = read();
	read();
	
	for(i=1;i<=m;i++){
		b[i] = read();
	}
	
	for(i=2;i<=(1ll<<40ll);i*=2){
		sa.clear();
		sb.clear();
		for(j=1;j<=n;j++){
			sa[a[j] % i]++;
			ans = max(ans, sa[a[j] % i]);
		}
		
		for(j=1;j<=m;j++){
			sb[b[j] % i]++;
			ans = max(ans, sb[b[j] % i] + sa[(b[j] + i / 2) % i]);
		}
	}
	
	printf("%d\n", max(ans, 2));
	
	return 0;
}