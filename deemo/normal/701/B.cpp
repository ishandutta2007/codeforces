#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, m;
map<int, int>	x, y;

int main(){
	scanf("%d %d", &n, &m);
	long long ans = ll(n) * n;
	while (m--){
		int a, b;	scanf("%d %d", &a, &b);
		if (x.count(a) == 0 || y.count(b) == 0){
			int temp = 1;
			if (x.count(a) == 0){
				temp += (n-1 - y.size());
			}
			if (y.count(b) == 0){
				temp += (n-1 - x.size());
			}
			x[a] = 1;
			y[b] = 1;
			ans -= temp;
		}
		printf("%lld ", ans);	
	}
	printf("\n");
	return 0;
}