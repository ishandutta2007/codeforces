#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
long long pre[maxn];
long long suf[maxn];
bool pv[maxn];
bool sv[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			pre[i] = a[i] - pre[i - 1];
			pv[i] = pv[i - 1] || (a[i] < pre[i - 1]);
		}
		
		sv[n + 1] = false;
		suf[n + 1] = 0;
		for(i=n;i>0;i--){
			suf[i] = a[i] - suf[i + 1];
			sv[i] = sv[i + 1] || (a[i] < suf[i + 1]);
		}
		
		bool flag = (pre[n] == 0 and !pv[n]);
		
		for(i=1;i<n;i++){
			if(pv[i - 1] or sv[i + 2]) continue;
			int x = a[i + 1], y = a[i];
			if(x < pre[i - 1]) continue;
			x -= pre[i - 1];
			if(y < x) continue;
			y -= x;
			if(y != suf[i + 2]) continue;
			flag = true;
			break;
		}
		
		printf(flag ? "YES\n" : "NO\n");
	}
	
	return 0;
}