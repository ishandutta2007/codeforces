#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n[2], A[2][MAXN], p[2][MAXN];
string s[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int w = 0; w < 2; w++){
		cin >> s[w];
		n[w] = s[w].size();

		for (int i = 0; i < n[w]; i++) {
			if (s[w][i] != 'A')
				A[w][i] = 0;
			else
				A[w][i] = 1;
			if (i && A[w][i])
				A[w][i] += A[w][i-1];
			p[w][i+1] = p[w][i] + (int)(s[w][i] != 'A');
		}
	}

	int q; cin >> q;
	string ans;
	while (q--){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2, l1--, l2--;
		int a0 = A[0][r1-1], a1 = A[1][r2-1];
		a0 = min(a0, r1-l1), a1 = min(a1, r2-l2);
		if (a0 < a1)
			ans += "0";
		else{
			r1 -= a1, r2 -= a1;
			if (r2 - l2 > 0 && r1 - l1 == 0)
				ans += "0";
			else if (r1 - l1 == 0)
				ans += "1";
			else {
				a0 -= a1;
				int t0 = p[0][r1] - p[0][l1], t1 = p[1][r2] - p[1][l2];
				if (s[0][r1-1] == 'A' && a0 % 3)
					t0 += 2;
				if (t0 > t1 || t0%2 != t1%2)
					ans += "0";
				else
					ans += "1";
			}
		}
	}
	cout << ans << "\n";
	return 0;
}