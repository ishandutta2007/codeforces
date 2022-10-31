#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 55;
int xa[N], xb[N], ya[N], yb[N];
int q[N];

vector<tuple<int,int,int,int>> moves;

int main() {	
	fio;
	moves.reserve(10800);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> xa[i] >> ya[i];
		--xa[i];
		--ya[i];
	}

	for(int i = 0; i < m; ++i) {
		cin >> xb[i] >> yb[i];
		--xb[i];
		--yb[i];
	}
	for(int i = 0; i < m; ++i)
		q[i] = i;
	// sep row
	sort(q, q+m, [=](const int& i, const int& j) -> bool {
		return xa[i] < xa[j];
	});
	for(int i = 0; i < m; ++i) {
		int j = q[i];
		while(xa[j] > i) {
			moves.emplace_back(xa[j], ya[j], xa[j]-1, ya[j]);
			--xa[j];
		}
	}
	for(int i = m-1; i >= 0; --i) {
		int j = q[i];
		while(xa[j] < i) {
			moves.emplace_back(xa[j], ya[j], xa[j]+1, ya[j]);
			++xa[j];
		}
	}

	// sort col
	sort(q, q+m, [=](const int& i, const int& j) -> bool {
		return yb[i] < yb[j];
	});
	for(int i = 0; i < m; ++i) {
		int j = q[i];
		while(ya[j] != i) {
			if(ya[j] > i) {
				moves.emplace_back(xa[j], ya[j], xa[j], ya[j]-1);
				--ya[j];
			} else {
				moves.emplace_back(xa[j], ya[j], xa[j], ya[j]+1);
				++ya[j];
			}
		}
	}

	// mix row
	for(int i = 0; i < m; ++i) {
		while(xa[i] != xb[i]) {
			if(xa[i] > xb[i]) {
				moves.emplace_back(xa[i], ya[i], xa[i]-1, ya[i]);
				--xa[i];
			} else {
				moves.emplace_back(xa[i], ya[i], xa[i]+1, ya[i]);
				++xa[i];
			}
		}
	}

	// mix col
	for(int i = 0; i < m; ++i) {
		int j = q[i];
		while(ya[j] > yb[j]) {
			moves.emplace_back(xa[j], ya[j], xa[j], ya[j]-1);
			--ya[j];
		}
	}
	for(int i = m-1; i >= 0; --i) {
		int j = q[i];
		while(ya[j] < yb[j]) {
			moves.emplace_back(xa[j], ya[j], xa[j], ya[j]+1);
			++ya[j];
		}
	}
	
	// print
	cout << moves.size() << endl;
	for(const auto& x : moves) {
		cout << get<0>(x)+1 << " "<< get<1>(x)+1 << " "<< get<2>(x)+1 << " "<< get<3>(x)+1 << "\n";
	}
}