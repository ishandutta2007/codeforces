#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

double m;

double a[1005];
double b[1005];

double eps = 1e-6;

bool check(double x){
	int i;
	
	x -= (m + x) / a[1];
	
	if(x < 0){
		return false;
	}
	
	for(i=2;i<=n;i++){
		x -= (m + x) / b[i];
		if(x < 0){
			return false;
		}
		
		x -= (m + x) / a[i];
		if(x < 0){
			return false;
		}
	}
	
	x -= (m + x) / b[1];
	if(x < 0){
		return false;
	}
	
	return true;
}

int main(){
	int i, j;
	double l = 0, r = 1e9;
	double mid;
	
	cin >> n >> m;
	
	for(i=1;i<=n;i++){
		
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		cin >> b[i];
	}
	
	if(!check(r + 1)){
		cout << -1 << endl;
		return 0;
	}
	
	while(r - l > eps){
		mid = (l + r) / 2;
		if(check(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	
	printf("%.10f\n", l);
	
	return 0;
}