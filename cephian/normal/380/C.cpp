#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string s;
const int N = 1000005;
int h[N],n,mn[N][22];

int qmn(int l, int r) {
	int a = r-l+1,b=-1;
	while(a) {
		a/=2;
		++b;
	}
	return min(mn[l][b],mn[r-(1<<b)+1][b]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	n = s.size();
	h[0] = mn[0][0] = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i-1] == '(') h[i] = h[i-1]+1;
		else h[i] = h[i-1]-1;
		mn[i][0] = h[i];
	}
	
	for(int k = 1; k < 22; ++k) {
		for(int i = 0; i <= n; ++i) {
			mn[i][k] = mn[i][k-1];
			if(i + (1<<(k-1)) <= n) {
				mn[i][k] = min(mn[i][k],mn[i+(1<<(k-1))][k-1]);
			}
		}
	}

	int q;
	cin >> q;
	while(q--) {
		int l,r;
		cin >> l >> r;
		int m = qmn(l-1,r)-h[l-1];
		int e = h[r]-h[l-1];
		cout << r-l+1+2*m-e << "\n";
		// cout << m << " " << e << endl;
	}


	return 0;
}