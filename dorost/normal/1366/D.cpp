/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234;
const int M = 3163;
int ans1[N], a[N], ans2[N];

bool is_prime(int x){
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0)
			return false;
	}
	return true;
}

int32_t main(){
	vector <int> v;
	for (int i = 2; i < M; i++){
		if (is_prime(i))
			v.push_back(i);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", a + i);
		int ans = 0, an1 = -1;
		int x = a[i];
		for (int j = 0; j < v.size(); j++){
			if (x % v[j] == 0){
				ans ++;
				an1 = v[j];
				break;
			}
		}
		if (an1 == -1){
			ans1[i] = -1;
			ans2[i] = -1;
			continue;
		}
		int y = x;
		while (y % an1 == 0){
			y /= an1;
		}
		if (y == 1){
			ans1[i] = -1;
			ans2[i] = -1;
			continue;
		}
		ans1[i] = an1;
		ans2[i] = y;
	}
	for (int i = 0; i < n; i++){
		printf("%d ", ans1[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++){
		printf("%d ", ans2[i]);
	}
}