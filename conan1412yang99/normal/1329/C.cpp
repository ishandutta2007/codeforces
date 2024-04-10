#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = (1 << 21) + 7;

int a[N], d[N];
int h, g;
int mp[N];

void upd(int i) {
	if(a[i] == 0) return;
	if(a[i*2] == 0 && a[i*2+1] == 0) {
		d[i] = __lg(i) + 1;
	}
	else {
		if(a[i*2] > a[i*2+1]) d[i] = d[i*2];
		else d[i] = d[i*2+1];
	}
	mp[a[i]] = i;
}

void del(int i) {
	mp[a[i]] = 0;
}

void go(int i) {
	if(a[i*2] == 0 && a[i*2+1] == 0) {
		del(i);
		a[i] = d[i] = 0;
		return;
	}	
	if(a[i*2] > a[i*2+1]) {
		del(i);
		a[i] = a[i*2];
		go(i*2);
		upd(i);
	} else {
		del(i);
		a[i] = a[i*2+1];
		go(i*2+1);
		upd(i);
	}
}

void solve() {
	cin >> h >> g;
	ll sum = 0;
	vi v;
	for(int i=1;i<(1<<h);i++) {
		cin >> a[i];
		sum += a[i];
		d[i] = h;
		mp[a[i]] = i;
		v.PB(a[i]);
	}
	sort(ALL(v));
	reverse(ALL(v));
	int ptr = 0;
	int min_d = g;
	vi ans;
	for(int i=0;i<((1<<h)-(1<<g));i++) {
		while(d[mp[v[ptr]]] <= min_d) ptr++;
		int j = mp[v[ptr]];
		sum -= a[j];
		ans.PB(j);
		if(j/2) del(j/2);
		go(j);
		if(j/2) upd(j/2);
	}
	cout << sum << endl;
	for(int i:ans) cout << i << " ";
	cout << endl;
	for(int i=1;i<(1<<h);i++) a[i] = 0, d[i] = 0;
	for(int i:v) mp[i] = 0;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}	
	
}