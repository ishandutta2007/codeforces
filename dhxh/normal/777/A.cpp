#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long n, p;

int f[10][5];

int main(){
	int i, j;
	
	cin >> n >> p;
	
	f[0][0] = 0;
	f[0][1] = 1;
	f[0][2] = 2;
	
	for(i=1;i<=5;i++){
		if(i % 2){
			f[i][0] = f[i - 1][1];
			f[i][1] = f[i - 1][0];
			f[i][2] = f[i - 1][2];
		}else{
			f[i][0] = f[i - 1][0];
			f[i][1] = f[i - 1][2];
			f[i][2] = f[i - 1][1];
		}
	}
	
	n = n % 6;
	
	cout << f[n][p] << endl;
	
	return 0;
}