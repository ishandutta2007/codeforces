#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>	

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];
long long b[maxn];

vector <long long> vec[65];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long g = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		for(j=60;j>=0;j--){
			if(a[i] % (1ll << j) == 0){
				vec[j].push_back(a[i]);
				break;
			}
		}
	}
	
	int x = 0;
	
	for(i=1;i<=60;i++){
		if(vec[i].size() > vec[x].size()){
			x = i;
		}
	}
	
	printf("%d\n", n - (int)vec[x].size());
	for(i=0;i<=60;i++){
		if(i == x)continue;
		for(auto j : vec[i]){
			printf("%lld ", j);
		}
	}
	if(vec[x].size() != n)printf("\n");
	
	return 0;
}