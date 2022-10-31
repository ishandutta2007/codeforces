#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int a = 0;
	while(n) {
		++a;
		n /=2;
	}
	cout << a << "\n";
}