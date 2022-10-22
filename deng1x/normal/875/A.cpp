#include <bits/stdc++.h>

bool check(int a, int b){
	int ret = a;
	while(a){
		ret += a % 10;
		a /= 10;
	}
	return ret == b;
}

int main(){
	int n;
	scanf("%d", &n);
	std::vector<int> vec;
	for(int i = std::max(1, n - 100); i <= n; ++ i){
		if(check(i, n)){
			vec.push_back(i);
		}
	}
	printf("%d\n", (int)(vec.size()));
	for(auto v : vec){
		printf("%d ", v);
	}
	puts("");
	return 0;
}