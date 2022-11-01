#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a[10];
int b[10];
int c[10];

int ans = 0;

int n;

int main(){
	int i, j;
	int x;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> x;
		a[x]++;
	}
	
	for(i=1;i<=n;i++){
		cin >> x;
		b[x]++;
	}
	
	for(i=1;i<=5;i++){
		c[i] = a[i] + b[i];
		if(c[i] % 2){
			cout << -1 << endl;
			return 0;
		}
		c[i] = c[i] / 2;
	}
	
	for(i=1;i<=5;i++){
		ans += abs(a[i] - c[i]);
	}
	
	cout << ans / 2 << endl;
	
	return 0;
}