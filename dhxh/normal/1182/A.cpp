#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	if(n % 2 == 1){
		cout << 0 << endl;
	}else{
		long long ans = 1;
		for(i=1;i<=n/2;i++){
			ans *= 2ll;
		}
		cout << ans << endl;
	}
	
	return 0;
}