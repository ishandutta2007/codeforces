#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

long long n, m, t;
long long a[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x = 1;
	
	cin >> n >> m;
	
	for(i=1;i<=m;i++){
		cin >> a[i];
		if(n % a[i] < n % a[x]){
			x = i;
		}
	}
	
	cout << x << " " << n / a[x] << endl;
	
	return 0;
}