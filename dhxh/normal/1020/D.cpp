#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int a[maxn];

int getans(int x){
	cout << "? " << x << endl;
	cin >> a[x];
	cout << "? " << x + n / 2 << endl;
	cin >> a[x + n / 2];
	return a[x + n / 2] - a[x];
}

int main(){
	int i, j;
	int l, r;
	int mid;
	int tmp;
	
	cin >> n;
	
	if((n / 2) & 1){
		cout << "! -1" << endl;
		return 0;
	}
	
	cout << "? " << 1 << endl;
	cin >> a[1];
	cout << "? " << n / 2 << endl;
	cin >> a[n / 2];
	cout << "? " << 1 + n / 2 << endl;
	cin >> a[1 + n / 2];
	cout << "? " << n << endl;
	cin >> a[n];
	
	if(a[1] == a[1 + n / 2]){
		cout << "! 1" << endl;
		return 0;
	}
	
	if(a[n / 2] == a[n]){
		cout << "! " << n / 2 << endl;
		return 0;
	}
	
	l = 1;
	r = n / 2;
	
	if(a[1 + n / 2] - a[1] > 0){
		while(l < r){
			mid = (l + r) / 2;
			tmp = getans(mid);
			if(tmp > 0){
				l = mid + 1;
			}else if(tmp < 0){
				r = mid;
			}else{
				cout << "! " << mid << endl;
				return 0;
			}
		}
	}else{
		while(l < r){
			mid = (l + r) / 2;
			tmp = getans(mid);
			if(tmp < 0){
				l = mid + 1;
			}else if(tmp > 0){
				r = mid;
			}else{
				cout << "! " << mid << endl;
				return 0;
			}
		}
	}
	
	
	cout << "! " << l << endl;
	
	return 0;
}