#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long h[maxn];

long long l[maxn], r[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(i=1;i<=n;i++){
			scanf("%lld", &h[i]);
		}
		
		bool flag = false;
		l[1] = h[1], r[1] = h[1] + m;
		
		for(i=2;i<=n;i++){
			l[i] = max(l[i - 1] - m + 1, h[i]);
			r[i] = min(r[i - 1] + m - 1, h[i] + m - 1 + m);
			if(r[i] - l[i] < m){
				flag = true;
				break;
			}
		}
		
		l[n] = max(l[n], h[n]);
		if(l[n] != h[n] or r[n] - l[n] < m){
			flag = true;
		}
		
		printf(flag ? "NO\n" : "YES\n");
	}
	
	return 0;
}