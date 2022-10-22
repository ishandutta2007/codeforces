#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int nd = (n+(k-1))/k;
	int x = nd*t;
	if (nd > 1 && d+t < x)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}