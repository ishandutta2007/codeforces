#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

string str;

int a[55], b[55], c[55];

int geta(string x){
	int i, j;
	int ans;
	
	for(i=0;i<m;i++){
		if('0' <= x[i] and x[i] <= '9'){
			ans = i;
			break;
		}
	}
	
	for(i=1;i<=m;i++){
		if('0' <= x[m - i] and x[m - i] <= '9'){
			return min(ans, i);
		}
	}
	return m;
}

int getb(string x){
	int i, j;
	int ans;
	
	for(i=0;i<m;i++){
		if('a' <= x[i] and x[i] <= 'z'){
			ans = i;
			break;
		}
	}
	
	for(i=1;i<=m;i++){
		if('a' <= x[m - i] and x[m - i] <= 'z'){
			return min(ans, i);
		}
	}
	return m;
}

int getc(string x){
	int i, j;
	int ans;
	
	for(i=0;i<m;i++){
		if(x[i] == '#' or x[i] == '*' or x[i] == '&'){
			ans = i;
			break;
		}
	}
	
	for(i=1;i<=m;i++){
		if(x[m - i] == '#' or x[m - i] == '*' or x[m - i] == '&'){
			return min(ans, i);
		}
	}
	return m;
}

int main(){
	int i, j, k;
	int ans;
	
	cin >> n >> m;
	
	ans = 3 * m;
	
	for(i=1;i<=n;i++){
		cin >> str;
		a[i] = geta(str);
		b[i] = getb(str);
		c[i] = getc(str);
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(i != j and i != k and j != k){
					ans = min(ans, a[i] + b[j] + c[k]);
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}