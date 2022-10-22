#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, a[MAXN], b[MAXN], sec[MAXN], sz;

bool check(int ln){
	int sm = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != a[i%ln])
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n-1; i; i--)
		a[i] -= a[i-1];
	for (int ln = 1; ln <= n; ln++)
		if (check(ln))
			sec[sz++] = ln;

	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << sec[i] << " ";
	cout << "\n";
	return 0;
}