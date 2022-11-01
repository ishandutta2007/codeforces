#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		int x = n;
		
		vector <pair <int, int> > ans;
		
		for(i=n-1;i>1;i--){
			while(x / i + (x % i > 0) >= i){
				ans.push_back({n, i});
				x = x / i + (x % i > 0);
			}
			ans.push_back({i, n});
		}
		
		printf("%d\n", (int)ans.size());
		for(auto [x, y] : ans){
			printf("%d %d\n", x, y);
		}
	}
	
	return 0;
}