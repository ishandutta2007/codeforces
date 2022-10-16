#include <bits/stdc++.h>
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

const int INF = 1e9 + 7, N = 3003;

int a[N];

signed main()
{
	IO_OP;
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	for(int i=0;i<n;i++) {
		if(s[i] == 'L') a[i] = 0;
		else a[i] = 1;
	}
	V<vi> G;
	int mx = 0;
	for(int i=0;i<n;i++) {
		vi v;
		for(int j=0;j<n-1;j++)
			if(a[j] == 1 && a[j+1] == 0) {
				v.PB(j);
				swap(a[j], a[j+1]);
				mx++;
				j++;
			}
		if(v.size()) G.PB(v);
	}
	if(k < G.size() || k > mx) {
		cout << -1 << endl;
		return 0;
	}
	int need = k, ptr = 0;
	for(int i=0;i<k;i++) {
		vi cur;
		if((int)G.size()-ptr < need) {
			cur.PB(G[ptr].back());
			G[ptr].pop_back();
			if(G[ptr].size() == 0) ptr++;
		} else {
			cur = G[ptr++];
		}
		cout << cur.size() << " ";
		for(int e:cur) cout << e + 1 << " ";
		cout << endl;
		need--;
	}
}