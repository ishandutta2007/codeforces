#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if((a) == (b + c + d)){
		cout << "YES";
		return 0;
	}
	if((b) == (a + c + d)){
		cout << "YES";
		return 0;
	}
	if((c) == (b + a + d)){
		cout << "YES";
		return 0;
	}
	if((d) == (b + c + a)){
		cout << "YES";
		return 0;
	}
	if((a + b) == (c + d)){
		cout << "YES";
		return 0;
	}
	if((a + c) == (b + d)){
		cout << "YES";
		return 0;
	}
	if((a + d) == (b + c)){
		cout << "YES";
		return 0;
	}
	if((b + c) == (a + d)){
		cout << "YES";
		return 0;
	}
	if((b + d) == (a + c)){
		cout << "YES";
		return 0;
	}
	cout << "NO";
}