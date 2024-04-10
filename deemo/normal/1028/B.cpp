#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int C = 2230;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	a = '9';
	for (int i = 0; i < C-1; i++){
		if (!(i&1))
			a = '1' + a;
		else
			a = '8' + a;
	}
	string b = "1";
	for (int i = 0; i < C-1; i++){
		if (!(i&1))
			b = '8' + b;
		else
			b = '1' + b;
	}
	cout << a << endl;
	cout << b << endl;
	return 0;
}