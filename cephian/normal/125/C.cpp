#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vector<int> M[200];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int d = 1;
	while(n >= d) {
		for(int i = 0; i < d; ++i)
			M[i].pb(n), M[d].pb(n--);
		++d;
	}
	cout << d << "\n";
	for(int i = 0; i < d; ++i) {
		for(int j = 0; j < M[i].size(); ++j) {
			if(j) cout << " ";
			cout << M[i][j];
		}
		cout << "\n";
	}
}