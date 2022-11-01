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

int main(){
	int i, j;
	int l = 1, r = 1e9;
	int x;
	int mid;
	
	cin >> m >> n;
	
	r = m;
	
	cout << 1 << endl;
	
	cin >> x;
	
	if(x == 0){
		return 0;
	}
	
	if(x == 1){
		a[0] = 1;
	}else{
		a[0] = -1;
	}
	
	for(i=1;i<n;i++){
		cout << 1 << endl;
		cin >> x;
		
		if(x == 1){
			a[i] = 1;
		}else{
			a[i] = -1;
		}
	}
	
	i = -1;
	
	l = 2;
	
	while(l < r){
		mid = (l + r) / 2;
		cout << mid << endl;
		i++;
		i %= n;
		cin >> x;
		x = x * a[i];
		
		if(x == 0){
			return 0;
		}
		
		if(x == 1){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	
	cout << l << endl;
	
	return 0;
}