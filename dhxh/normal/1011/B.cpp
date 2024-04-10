#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int a[105];
int ans = 0;

int main(){
	int i, j;
	int x;
	
	cin >> n >> m;
	
	for(i=1;i<=m;i++){
		cin >> x;
		a[x]++;
	}
	
	for(i=1;i<=100;i++){
		x = 0;
		for(j=1;j<=100;j++){
			x += a[j] / i;
		}
		
		if(x >= n){
			ans = i;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}