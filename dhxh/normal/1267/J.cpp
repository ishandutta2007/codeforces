#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;

int t, n;

int cnt[maxn];

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++)cnt[i] = 0;
		vector <int> vec;
		
		for(i=1;i<=n;i++){
			scanf("%d", &x);
			cnt[x]++;
		}
		for(i=1;i<=n;i++){
			if(cnt[i]){
				vec.push_back(cnt[i]);
			}
		}
		
		sort(vec.begin(), vec.end());
		
		int ans = n;
		
		for(i=2;i<=vec[0]+1;i++){
			bool flag = false;
			int sum = 0;
			for(auto j : vec){
				if(j % i == 0){
					sum += j / i;
				}else if(j % i + j / i >= i - 1){
					sum += j / i + 1;
				}else{
					flag = true;
					break;
				}
			}
			
			if(!flag){
				ans = min(ans, sum);
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}