#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

int b, y, r;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	int ans = 0;
	
	cin >> y >> b >> r;
	
	for(i=1;i<=y;i++){
		for(j=1;j<=b;j++){
			for(k=1;k<=r;k++){
				if(i + 1 == j and j + 1 == k){
					ans = max(ans, i + j + k);
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}