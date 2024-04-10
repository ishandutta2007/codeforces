#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e3 + 5;

int n, m, t;

long long a[maxn];
long long b[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long sqr(long long x){
	return x * x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		b[i] = read();
	}
	
	while(true){
		vector <int> vec[2][2];
		
		for(i=n;i>0;i--){
			a[i] = a[i] - a[1];
			b[i] = b[i] - b[1];
		}
		
		for(i=1;i<=n;i++){
			vec[(a[i] % 2 + 2) % 2][(b[i] % 2 + 2) % 2].push_back(i);
		}
		
		if(vec[0][0].size() + vec[1][1].size() != 0 and vec[0][0].size() + vec[1][1].size() != n){
			printf("%d\n", (int)vec[0][0].size() + (int)vec[1][1].size());
			for(auto x : vec[0][0]){
				printf("%d ", x);
			}
			
			for(auto x : vec[1][1]){
				printf("%d ", x);
			}
			printf("\n");
			break;
		}
		
		if(vec[0][0].size() == n){
			for(i=1;i<=n;i++){
				a[i] /= 2;
				b[i] /= 2;
			}
		}else{
			printf("%d\n", (int)vec[0][0].size());
			for(auto x : vec[0][0]){
				printf("%d ", x);
			}
			printf("\n");
			break;
		}
	}
	
	return 0;
}