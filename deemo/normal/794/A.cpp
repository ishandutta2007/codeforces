#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, l, r; cin >> x >> l >> r;
	int n;	cin >> n;
	int ans = 0;
	while (n--){
		int y;	cin >> y;
		if (l < y && y < r) ans++;
	}
	cout << ans << endl;
	return 0;
}