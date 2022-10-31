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
	
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if((i ^ j) <= n and (i ^ j) >= j and i + j > (i ^ j)){
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}