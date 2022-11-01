#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n;
long long ans = 0;

int a[1005];

int maxn = -100;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	
	cout << (maxn ^ a[n]) << endl;
	
	return 0;
}