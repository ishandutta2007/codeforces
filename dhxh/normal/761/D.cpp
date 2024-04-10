#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, l, r;

int a[100005];
int b[100005];
int c[100005];
int p[100005];

bool flag = true;

int main(){
	int i, j;
	int minb = 1000000007;
	int maxb = 0;
	int d = 0;
	
	cin >> n >> l >> r;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		cin >> p[i];
	}
	
	for(i=1;i<=n;i++){
		b[i] = a[i] + p[i];
		maxb = max(b[i], maxb);
		minb = min(b[i], minb);
	}
	
	if(maxb > r){
		d = maxb - r;
		d = d * (-1);
		if(minb + d < l){
			flag = false;
		}else{
			flag = true;
		}
	}else if(minb < l){
		d = l - minb;
		if(maxb + d > r){
			flag = false;
		}else{
			flag = true;
		}
	}
	
	if(flag){
		for(i=1;i<n;i++){
			cout << b[i] + d << " ";
		}
		
		cout << b[n] + d << endl;
	}else{
		cout << -1 << endl;
	}
	
	
	return 0;
}