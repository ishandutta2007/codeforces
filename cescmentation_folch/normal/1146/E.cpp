#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

const int N = 1e5 + 10;
int T[4*N];
int lazy[4*N];

void fes(int& a, int b) {
	if (b == 3 or b == 0) a ^= b;
	else a = b;
}

void actu(int node, bool f) {
	fes(T[node],lazy[node]);
	if (!f) {
		fes(lazy[2*node],lazy[node]);
		fes(lazy[2*node +1],lazy[node]);
	}
	lazy[node] = 0;
}

void ins(int node, int a, int b, int x, int y, int val) {
	actu(node, a == b);
	if (b < x or y < a) return;
	if (x <= a and b <= y) {
		fes(T[node],val);
		if (a != b) {
			fes(lazy[2*node],val);
			fes(lazy[2*node+1],val);
		}
		return;
	}
	ins(2*node,a,(a+b)/2,x,y,val);
	ins(2*node+1,1+(a+b)/2,b,x,y,val);
}

int que(int node, int a, int b, int x) {
	actu(node, a == b);
	if (b < x or x < a) return 0;
	if (a == b) return T[node];
	return (que(2*node, a , (a+b)/2, x) | que(2*node+1,1+(a+b)/2,b,x));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vi V(n);
	for (auto& x : V) cin >> x;
	while (q--) {
		char a;
		int val;
		cin >> a >> val;
		if (a == '<') {
			if (val > 0) {
				ins(1,0,N,0,val-1,3);
				ins(1,0,N,val,N,1);
			} else {
				ins(1,0,N,-val+1,N,1);
			}
		} else {
			if (val < 0) {
				ins(1,0,N,0,-val-1,3);
				ins(1,0,N,-val,N,2);
			} else {
				ins(1,0,N,val+1,N,2);
			}
		}
	}
	bool firs = true;
	for (auto x : V) {
		int v = que(1, 0, N, abs(x));
		if (!firs) cout << ' ';
		firs = false;
		if ((x < 0 and (v&1)) or (x > 0 and (v&2))) cout << -x;
		else cout << x;
	}
	cout << '\n';
}