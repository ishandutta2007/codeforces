#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int ans = 0;
	
	cin >> n;
	
	for(i=2;i<=n;i++){
		if(n % i == 0){
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}