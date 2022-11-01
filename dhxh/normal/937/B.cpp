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
	int k;
	bool flag;
	
	cin >> n >> m;
	
	for(i=m;i>n;i--){
		flag = true;
		for(j=2;j<=min(n, (int)sqrt(i));j++){
			if(i % j == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << i << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}