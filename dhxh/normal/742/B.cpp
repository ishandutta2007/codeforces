#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int a[100005];
long long v[500005];

long long read(){
	long long x;
	cin >> x;
	return x;
}

int main(){
	int i, j;
	long long ans = 0;
	
	n = read();
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		v[a[i]]++;
	}
	
	for(i=n;i>0;i--){
		v[a[i]]--;
		ans += v[a[i] ^ m];
	}
	
	cout << ans << endl;
	
	return 0;
}