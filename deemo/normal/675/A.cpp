#include<iostream>

using namespace std;

typedef long long ll;

int main(){
	ll a, b, c;	cin >> a >> b >> c;
	b -= a;
	if (b == 0){
		cout << "YES\n";
		return 0;
	}
	if (c == 0){
		cout << "NO\n";
		return 0;
	}
	if (b > 0 && c < 0)
		cout << "NO\n";
	else if (b < 0 && c > 0)
		cout << "NO\n";
	else{
		c = abs(c);
		b = abs(b);
		if (b % c == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}