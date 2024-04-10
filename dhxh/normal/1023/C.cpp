#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m;

string a;

string ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int t, l = 0, r = 0;
	
	cin >> n >> m;
	
	cin >> a;
	
	t = m / 2;
	
	for(i=0;i<n;i++){
		if(l == t and r == t){
			break;
		}
		
		if(a[i] == '(' and l < t){
			ans += '(';
			l++;
		}else if(a[i] == ')' and r < t and l > r){
			ans += ')';
			r++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}