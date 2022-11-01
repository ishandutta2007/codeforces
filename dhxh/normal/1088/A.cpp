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
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i % j == 0 and i * j > n and i / j < n){
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}