#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	int a, b, c, d;
	char ch;
	cin >> a >> ch >> b >> c >> ch >> d;
	int n = a - c, m = b - d;
	if(m < 0){
		m += 60;
		n --;
	}
	if (n < 0){
		n += 24;
	}
	cout << (n < 10 ? "0" : "") << n << ':';
	cout << (m < 10 ? "0" : "") << m;
}