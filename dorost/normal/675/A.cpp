/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool pos (int x){
	if (x < 0)
		return false;
	return true;
}

int32_t main(){
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b){
		cout << "Yes";
	}else if (c == 0){
		cout << "No";
	}else{
		if (pos(a - b) == pos (c)){
			cout << "No";
		}else if (abs(a - b) % abs(c) == 0)
			cout << "Yes";
		else
			cout << "No";
	}
}