#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

long long a[maxn];

string str;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	long long l = -1e9, r = 1e9;
	
	cin >> n;
	
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	
	cin >> str;
	
	for(i=4;i<n;i++){
		if(str[i] == '1' and str[i - 1] == '0' and str[i - 2] == '0' and str[i - 3] == '0' and str[i - 4] == '0'){
			l = max(l, max(max(a[i - 1], a[i - 2]), max(a[i - 3], a[i - 4])));
			l = max(l, a[i]);
		}
		
		if(str[i] == '0' and str[i - 1] == '1' and str[i - 2] == '1' and str[i - 3] == '1' and str[i - 4] == '1'){
			r = min(r, min(min(a[i - 1], a[i - 2]), min(a[i - 3], a[i - 4])));
			r = min(r, a[i]);
		}
	}
	
	l++;
	r--;
	
	cout << l << " " << r << endl;
	
	return 0;
}