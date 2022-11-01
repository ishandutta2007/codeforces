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

long long n, m, t;

long long a[maxn];
long long ans[maxn];

vector <pair <long long, long long> > vec;

long long read(){
	long long x;
	scanf("%lld", &x);
	return x;
}

int main(){
	int i, j;
	long long x, y;
	long long minx = 0;
	long long tmp = 0;
	bool flag;
	
	n = read();
	
	for(i=1;i<=n/2;i++){
		a[i] = read();
		if(a[i] % 2 == 0 and a[i] % 4 != 0){
			printf("No\n");
			return 0;
		}
	}
	
	//dfs(1, n, 0);
	
	for(i=1;i<=n/2;i++){
		vec.clear();
		for(j=1;j<sqrt(a[i]);j++){
			if(a[i] % j == 0 and (j + a[i] / j) % 2 == 0){
				vec.push_back(make_pair(j, a[i] / j));
			}
		}
		
		flag = false;
		
		for(j=vec.size()-1;j>=0;j--){
			x = (vec[j].second + vec[j].first) / 2;
			y = (vec[j].second - vec[j].first) / 2;
			
			if(y > minx){
				ans[i] = y * y - tmp;
				minx = x;
				tmp = x * x;
				flag = true;
				break;
			}
		}
		
		if(!flag){
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
	for(i=1;i<=n/2;i++){
		printf("%I64d %I64d ", ans[i], a[i]);
	}
	printf("\n");
	
	return 0;
}