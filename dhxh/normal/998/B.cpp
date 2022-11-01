#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
int b;

int a[105];

int isc[105];

int f[105][105];

int main(){
	int i, j;
	
	cin >> n >> b;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		if(a[i] % 2){
			isc[i + 1] = isc[i] + 1;
		}else{
			isc[i + 1] = isc[i] - 1;
		}
	}
	
	for(i=2;i<=n;i++){
		for(j=0;j<=b;j++){
			f[i][j] = f[i - 1][j];
		}
		if(isc[i] == 0){
			for(j=0;j<=b-abs(a[i] - a[i - 1]);j++){
				f[i][j + abs(a[i] - a[i - 1])] = max(f[i][j + abs(a[i] - a[i - 1])], f[i - 1][j] + 1);
			}
		}
	}
	
	cout << f[n][b] << endl;
	
	return 0;
}