#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int s1 = 0;
	for (int w = 0; w < 4; w++){
		int x; cin >> x;
		s1 += x;
	}

	int ans = 1;
	for (int i = 0; i < n-1; i++){
		int sm = 0;
		for (int w = 0; w < 4; w++){
			int x; cin >> x;
			sm += x;
		}
		if (sm > s1)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}