#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	int ans = min({a, b-1, c-2});
	cout << ans + ans+1 + ans+2 << endl;
	return 0;
}