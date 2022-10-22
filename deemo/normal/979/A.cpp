#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n; cin >> n;
	n++;
	if (n == 1)
		cout << "0\n";
	else
		if (n%2 == 0)
			cout << n/2 << endl;
		else
			cout << n << endl;
	return 0;
}