#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int n, m, t;

vector <int> p[maxn];
int a[maxn];

int mx[maxn];
bool ans[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++) p[i].clear(), ans[i] = false;
		set <int> s;
		s.insert(0);
		s.insert(n + 1);
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
			p[a[i]].push_back(i);
		}
		
		for(i=1;i<=n;i++){
			mx[i] = 0;
			for(auto j : p[i]){
				auto x = s.lower_bound(j);
				auto y = x;
				y--;
				mx[i] = max(mx[i], *x - *y - 1);
			}
			
			for(auto j : p[i]){
				s.insert(j);
			}
		}
		
		m = mx[1];
		
		for(i=1;i<=n;i++){
			m = min(m, mx[i]);
			if(m >= n - i + 1){
				ans[n - i + 1] = true;
			}
		}
		
		for(i=1;i<=n;i++) printf("%d", ans[i]);
		printf("\n");
	}
	
	return 0;
}