#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int C = 256;

int n, k, a[MAXN];
set<int> st;

bool ok(int l, int r){
	auto it = st.upper_bound(l); it--;
	l = *it;
	it = st.upper_bound(r);
	r = *it;
	return r-l <= k;
}

void apply(int l, int r){
	auto it = st.upper_bound(l); it--;
	l = *it;
	it = st.upper_bound(r);
	r = *it;
	while (true){
		it = st.upper_bound(l);
		if (*it == r) break;
		st.erase(it);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= C; i++) st.insert(i);
	for (int i = 0; i < n; i++){
		int lo = -1, hi = a[i];
		while (hi-lo>1){
			int mid = hi+lo>>1;
			if (ok(mid, a[i]))
				hi = mid;
			else
				lo = mid;
		}
		apply(hi, a[i]);
		cout << hi << " ";
	}
	cout << "\n";
	return 0;
}