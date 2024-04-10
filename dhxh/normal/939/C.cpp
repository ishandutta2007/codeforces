#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

long long a[maxn];
long long sum[maxn];

int s, f;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x = 1;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	
	for(i=1;i<=n;i++){
		sum[n + i] = sum[n + i - 1] + a[i];
	}
	
	cin >> s >> f;
	
	for(i=1;i<=n;i++){
		if(sum[i + f - s - 1] - sum[i - 1] > sum[x + f - s - 1] - sum[x - 1]){
			x = i;
		}else if(sum[i + f - s - 1] - sum[i - 1] == sum[x + f - s - 1] - sum[x - 1]){
			if(((s - x) % n + n) % n + 1 > ((s - i) % n + n) % n + 1){
				x = i;
			}
		}
	}
	
	cout << ((s - x) % n + n) % n + 1 << endl;
	
	return 0;
}