#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int a, b;
	cin >> a >> b;
	int n = (a + b) / 2;
	int sa = abs(n - a), sb = abs(b - n);
	cout << (sa * sa + sa + sb * sb + sb) / 2;
}