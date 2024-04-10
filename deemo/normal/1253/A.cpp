#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i], b[i] -= a[i];
		int mx = 0, mn = 1e9, cnt = 0;
		bool done = false;
		for (int i = 0; !done && i < n; i++) {
			if (b[i] < 0) {
				done = true;
				cout << "NO\n";
			}
			if (b[i] > 0){
				mx = max(mx, b[i]);
				mn = min(mn, b[i]);
				cnt++;
			}
		}
		if (done)
			continue;
		if (cnt == 0){
			cout << "YES\n";
		}
		else if (mx != mn) {
			done = true;
			cout << "NO\n";
		}
		else{
			int first = 0;
			while (b[first] != mx)
				first++;
			int last = n-1;
			while (b[last] != mx)
				last--;
			if (last - first + 1 != cnt)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}