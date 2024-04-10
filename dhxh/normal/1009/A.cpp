#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

int c[1005];
int a[1005];

int ans = 0;

int main(){
	int i, j;
	
	cin >> n >> m;
	
	for(i=1;i<=n;i++){
		cin >> c[i];
	}
	
	for(i=1;i<=m;i++){
		cin >> a[i];
	}
	
	for(i=1,j=1;i<=n and j<=m;i++){
		if(c[i] <= a[j]){
			j++;
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}