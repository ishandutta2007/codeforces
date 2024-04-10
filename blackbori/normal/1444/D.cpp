#include <bits/stdc++.h>

using namespace std;
using pii = pair <int, int>;

bitset <1 << 20> D[1010];
int A[1010], B[1010];
int n, m, a, b;

bool can(vector <int> XA, vector <int> YA, vector <int> XB, vector <int> YB, int opt)
{
	int i, x, y;
	vector <pii> A;
	sort(XA.rbegin(), XA.rend()); sort(XB.begin(), XB.end());
	sort(YA.rbegin(), YA.rend()); sort(YB.begin(), YB.end());

	for(i = 0; i < YA.size(); i ++) XA.push_back(-YA[i]);
	for(i = 0; i < YB.size(); i ++) XB.push_back(-YB[i]);
	x = 0; y = 0;
	for(i = 0; i < n; i ++){
		A.emplace_back(x, y);
		x += XA[i];
		A.emplace_back(x, y);
		y += XB[i];
		if(XA[i] > 0 && XB[i] < 0) return 0;
	}
	cout << "Yes\n";
	for(auto [x, y]: A){
		if(opt) swap(x, y);
		cout << x << " " << y << "\n";
	}
	return 1;
}

void tc()
{
	int i, f, x, y;

	cin >> n; a = 0;
	for(i = 1; i <= n; i ++) cin >> A[i], a += A[i];
	cin >> m; b = 0;
	for(i = 1; i <= m; i ++) cin >> B[i], b += B[i];

	if(n != m || a % 2 == 1 || b % 2 == 1) { cout << "No\n"; return; }
	a /= 2; b /= 2;

	vector <int> XA, XB, YA, YB;

	for(f = 0; f < 2; f ++){
		D[0][0] = 1;
		for(i = 1; i <= n; i ++){
			D[i] = D[i - 1] | (D[i - 1] << A[i]);
		}

		if(!D[n][a]) { cout << "No\n"; return; }

		for(i = n; i >= 1; i --){
			if(!D[i - 1][a]) a -= A[i], XA.push_back(A[i]);
			else YA.push_back(A[i]);
		}

		swap(XA, XB); swap(YA, YB); swap(A, B); swap(a, b); swap(n, m);
	}

	for(i = 0; i < 4; i ++){
		if(i & 1) swap(XA, YA);
		if(i & 2) swap(XB, YB);
		if(can(XA, YA, XB, YB, 0)) return;
		if(can(XB, YB, XA, YA, 1)) return;
	}

	cout << "No\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	for(; t --; ) tc();

	return 0;
}