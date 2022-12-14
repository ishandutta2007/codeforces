#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[150005], m[150005];

int32_t main() {
	

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=a[i]-1;j<=a[i]+1;j++) {
			if(j <= 0) continue;
			if(m[j] == 0) {
				m[j] = 1;
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}