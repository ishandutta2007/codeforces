#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define maxn 500009
using namespace std;
int n, c, d;
int p1[maxn], b1[maxn], p2[maxn], b2[maxn];
int m1, m2;
int ans = 0;
int bin[maxn];

void update(int x, int v){
	while(x < maxn){
		bin[x] = max(bin[x], v);
		x += x & -x;
	}
}

int getsum(int x){
	int sum = 0;
	while(x > 0){
		sum = max(sum, bin[x]);
		x -= x & -x;
	}
	return sum;
}

int solve(int *b, int *p, int n, int m){
	memset(bin, 0, sizeof(bin));
	if(n < 2)
		return 0;
	update(p[1], b[1]);
	int ans = 0;
	for(int i = 2; i <= n; i++){
		if(p[i] <= m){
			int val = getsum(m - p[i]);
			if(val > 0)
				ans = max(ans, val + b[i]);
		}
		update(p[i], b[i]);
	}
	return ans;
}
int main(){
	int a = 0, b = 0;
	cin >> n >> c >> d;
	for(int i = 1; i <= n; i++){
		int x, y;
		char s[10];
		scanf("%d%d%s", &x, &y ,s);
		if(s[0] == 'C'){
			m1++;
			b1[m1] = x;
			p1[m1] = y;
			if(y <= c)
				a = max(a, x);
		}
		else{
			m2++;
			b2[m2] = x;
			p2[m2] = y;
			if(y <= d)
				b = max(b, x);
		}
	}
	if(a >= 1 && b >= 1)
		ans = max(ans, a + b);
	ans = max(ans, solve(b1, p1, m1, c));
	ans = max(ans, solve(b2, p2, m2, d));
	printf("%d\n", ans);
	return 0;
}