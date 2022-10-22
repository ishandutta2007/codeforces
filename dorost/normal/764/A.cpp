#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int a, b, n;
	cin >> a >> b >> n;
	cout << n / ((a * b) / __gcd(a,b));
}