#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;
	int x, y;	cin >> x >> y;
	int d1 = abs(a-c), d2 = abs(b-d);

	if (d1%x == 0 && d2 % y == 0){
		d1 /= x;
		d2 /= y;
		if (d1%2 == d2%2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else
		cout << "NO\n";
	return 0;
}