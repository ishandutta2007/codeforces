#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

vector<ld> xor_mlt(const vector<ld>& P, const vector<ld>& Q) {
	vector<ld> R(256,0);
	for(int i = 0; i < 256; ++i) {
		for(int j = 0; j < 256; ++j) {
			R[i^j] += P[i]*Q[j];
		}
	}
	return R;
}

vector<ld> xor_pw(const vector<ld>& P,int e) {
	if(e == 1) return P;
	if(e&1) {
		return xor_mlt(P,xor_pw(P,e-1));
	}
	vector<ld> Q = xor_pw(P,e/2);
	return xor_mlt(Q,Q);
}

int n,x;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<ld> P(256,0);
	cin >> n >> x;
	for(int i = 0; i <= x; ++i) {
		cin >> P[i];
	}
	cout << 1-xor_pw(P,n)[0] << "\n";


	return 0;
}