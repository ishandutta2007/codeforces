/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= 100000; i++){
		if (i % 2){
			a -= i;
			if (a < 0)
				return cout << "Vladik", 0;
		}else{
			b -= i;
			if (b < 0)
				return cout << "Valera", 0;
		}
	}
}