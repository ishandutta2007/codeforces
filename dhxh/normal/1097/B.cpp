#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

bool f[25][405];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x;
	cin >> n;
	
	f[0][0] = true;
	
	for(i=1;i<=n;i++){
		x = read();
		for(j=0;j<=360;j++){
			f[i][(j + x) % 360] |= f[i - 1][j];
			f[i][(j - x + 360) % 360] |= f[i - 1][j];
		}
	}
	
	if(f[n][0]){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}