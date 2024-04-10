#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;

int n, m, t;

bool vis[maxn];

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=2*n;i++){
			vis[i] = false;
		}
		
		vector <int> A, B;
		
		for(i=1;i<=n;i++){
			scanf("%d", &x);
			A.push_back(x);
			vis[x] = true;
		}
		
		for(i=1;i<=2*n;i++){
			if(!vis[i]) B.push_back(i);
		}
		
		vector <int> v(n + 5);
		
		for(i=0;i<A.size();i++){
			x = A[i];
			int c = lower_bound(B.begin(), B.end(), x) - B.begin();
			if(max(0, i - c + 1) <= i){
				v[max(0, i - c + 1)]++;
				v[i + 1]--;
			}
			if(n - c){
				v[i + 1]++;
				v[min(n, i + n - c) + 1]--;
			}
		}
		
		for(i=1;i<=n;i++) v[i] += v[i - 1];
		
		int ans = 0;
		for(i=0;i<=n;i++){
			if(v[i] == n) ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}