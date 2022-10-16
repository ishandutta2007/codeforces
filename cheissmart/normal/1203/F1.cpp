#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

bool solve() {
	int n, r;
	cin >> n >> r;
	vector<pi> pos, neg;
	for(int i=0;i<n;i++) {
		int a, b;
		cin >> a >> b;
		if(b >= 0)
			pos.EB(a, b);
		else
			neg.EB(a, b);
	}
	sort(ALL(pos));
	for(int i=0;i<pos.size();i++) {
		if(r < pos[i].F) return false;
		r += pos[i].S;
	}
	sort(ALL(neg), [](pi a, pi b) -> bool{
		return a.F + a.S > b.F + b.S;
	});
	for(int i=0;i<neg.size();i++) {
		if(r < neg[i].F) return false;
		r += neg[i].S;
	}
	return r >= 0;
}

int main()
{
	IO_OP;
	
	if(solve()) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}