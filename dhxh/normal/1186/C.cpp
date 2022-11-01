#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string a, b;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int d = 1;
	int ans = 0;
	
	cin >> a >> b;
	
	for(i=0;i<b.length();i++){
		if(a[i] != b[i]){
			d ^= 1;
		}
	}
	
	ans += d;
	
	for(i=b.length();i<a.length();i++){
		if(a[i - b.length()] != a[i]){
			d ^= 1;
		}
		ans += d;
	}
	
	cout << ans << endl;
	
	return 0;
}