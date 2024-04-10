#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

map<int, int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (x && mp[x-1] == 0){
			cout << i << "\n";
			return 0;
		}
		mp[x] = i;
	}
	cout << -1 << "\n";
	return 0;
}