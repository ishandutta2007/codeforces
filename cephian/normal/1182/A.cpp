#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll n;
	cin >> n;
	if(n % 2 == 1) cout << "0\n";
	else cout << (1<<(n/2)) << "\n";
}