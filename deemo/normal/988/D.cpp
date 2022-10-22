#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const ll INF = 1e10;

ll n, a[MAXN];
set<ll> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int mx = 1;
	for (int i = 0; i < n; i++){
		st.insert(a[i]);
		for (ll w = 0; (1ll<<w) <= INF; w++){
			ll temp = 1ll<<w;
			if (st.count(a[i] - temp)){
				mx = max(mx, 2);
				if (st.count(a[i] - temp*2)){
					cout << 3 << "\n";
					cout << a[i] << " " << a[i]-temp << " " << a[i]-temp*2 << "\n";
					return 0;
				}
			}
		}
	}
	if (mx == 1){
		cout << "1\n";
		cout << a[0] << "\n";
		return 0;
	}

	st.clear();
	for (int i = 0; i < n; i++){
		st.insert(a[i]);
		for (ll w = 0; (1ll<<w) <= INF; w++){
			ll temp = 1ll<<w;
			if (st.count(a[i] - temp)){
				cout << 2 << "\n";
				cout << a[i] << " " << a[i]-temp << "\n";
				return 0;
			}
		}
	}
	return 0;
}