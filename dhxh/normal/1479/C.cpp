#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int b;

vector <pair <int, int> > e[50];

int l, r;

int cnt[50];

int main(){
	int i, j;
	
	scanf("%d%d", &l, &r);
	b = l - 1;
	r = r - l + 1;
	l = 1;
	
	e[1].push_back({0, 1});
	cnt[0] = cnt[1] = 1;
	
	if(r > 1){
		for(i=2;;i++){
			if((1 << (i - 1)) >= r){
				n = i;
				break;
			}
			
			e[i].push_back({0, 1});
			cnt[i] = 1;
			for(j=1;j<i;j++){
				e[i].push_back({j, cnt[i]});
				cnt[i] += cnt[j];
			}
		}
		
		cnt[n] = 1;
		e[n].push_back({0, 1});
		for(i=n-1;i>0;i--){
			if(cnt[i] + cnt[n] <= r){
				e[n].push_back({i, cnt[n]});
				cnt[n] += cnt[i];
			}
		}
		
		if(b){
			e[n + 1].push_back({n, b});
			n += 2;
		}else{
			n += 1;
		}
	}else{
		if(b){
			e[2].push_back({1, b});
			n = 3;
		}else{
			n = 2;
		}
	}
	
	for(i=0;i<n;i++) m += e[i].size();
	
	if(n > 32){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n%d %d\n", n, m);
	
	for(i=n-1;i>=0;i--){
		for(auto [j, w] : e[i]){
			printf("%d %d %d\n", n - i, n - j, w);
		}
	}
	
	return 0;
}