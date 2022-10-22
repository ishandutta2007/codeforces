#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	string a, b;
	cin >> a >> b;
	reverse(b.begin(), b.end());
	cout << stoi(a) + stoi(b);
}