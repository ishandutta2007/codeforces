#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int x[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
		int y; cin >> y;
	}
	sort(x, x + n);
	if (x[1] > 0 || x[n-2] < 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}