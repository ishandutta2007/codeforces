#include <bits/stdc++.h>
using namespace std;
 
#define Debug(x)
typedef int regular_int;
// #define int ll
typedef long long ll;
 
int A[20][20];
string s;
int n, p;
bool B[17][17][1 << 17], valid[1 << 17];
int cnt[20];
 
regular_int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;
 
	cin >> n >> p;
	cin >> s;
	for(int i = 0; i < n; ++i) {
		++cnt[s[i] - 'a'];
	}
	for(int i = 0; i < p; ++i) {
		for(int j = 0; j < p; ++j) {
			cin >> A[i][j];
		}
	}
 
	for(int i = 0; i < p; ++i) {
		for(int j = 0; j < p; ++j) {
			if(A[i][j])continue;
			int pos = 0;
			while(pos < n) {
				while(pos < n && s[pos] - 'a' != i)++pos;
				int b = 0;
				++pos;
				while(pos < n && s[pos] - 'a' != j) {
					if(s[pos] - 'a' == i)
						b = 0;
					else
						b |= 1 << (s[pos] - 'a');
					++pos;
				}
				if(pos < n)
					B[i][j][b] = true;
			}
			for(int b = 0; b < (1 << p); ++b) {
				for(int k = 0; !B[i][j][b] && k < p; ++k) {
					if((b & (1 << k)) > 0 && B[i][j][b - (1 << k)]) {
						B[i][j][b] = true;
					}
				}
			}
		}
	}
 
	int res = n;
	valid[0] = true;
	for(int b = 1; b < (1 << p); ++b) {
		valid[b] = true;
		for(int i = 0; valid[b] && i < p; ++i) {
			if((b & (1 << i)) > 0)continue;
			for(int j = 0; valid[b] && j < p; ++j) {
				if((b & (1 << j)) > 0)continue;
				valid[b] = !B[i][j][b];
			}
		}
//		Debug (cout << "valid1[" << b << "]: " << valid[b] << endl;)
		if(!valid[b])continue;
		valid[b] = false;
		for(int i = 0; !valid[b] && i < p; ++i) {
			if((b & (1 << i)) > 0 && valid[b - (1 << i)]) {
				Debug(cout << "parent: " << (b - (1 << i)) << endl;)
				valid[b] = true;
			}
		}
		Debug(cout << "valid2[" << b << "]: " << valid[b] << endl;)
		if(valid[b]) {
			int sum = 0;
			for(int i = 0; i < p; ++i) {
				if((b & (1 << i)) == 0)sum += cnt[i];
			}
			res = min(res, sum);
		}
 
	}
	cout << res << endl;
	return 0;
}