#include <bits/stdc++.h>

#define MAXN (200010)

char s[MAXN];
std::vector<int> vec[MAXN];
std::queue<int> z, o;

int main(){
	scanf("%s", s);
	int n = strlen(s);
	int zero = 0, one = 0;
	for(int i = 0; i < n; ++ i){
		zero += s[i] == '0';
		one  += s[i] == '1';
	}
	int k = zero - one;
	if(k <= 0){
		printf("-1\n");
		return 0;
	}
	for(int i = 1; i <= k; ++ i) z.push(i);
	for(int i = 0; i < n; ++ i){
		if(s[i] == '0'){
			if(z.empty()){
				return printf("-1\n"), 0;
			}
			int u = z.front(); z.pop();
			vec[u].push_back(i + 1);
			o.push(u);
		}
		else{
			if(o.empty()){
				return printf("-1\n"), 0;
			}
			int u = o.front(); o.pop();
			vec[u].push_back(i + 1);
			z.push(u);
		}
	}
	printf("%d\n", k);
	for(int i = 1; i <= k; ++ i){
		int t = vec[i].size();
		printf("%d", t);
		for(int j = 0; j < t; ++ j){
			printf(" %d", vec[i][j]);
		}
		printf("\n");
	}
	return 0;
}