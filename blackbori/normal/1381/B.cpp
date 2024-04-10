#include <bits/stdc++.h>

using namespace std;

bool B[4040];
int D[4040];
vector <int> S;
int n;

void tc()
{
	int i, j, t;

	cin >> n;

	S.clear();
	for(i = 1; i <= n + n; i ++){
		cin >> D[i];
		if(S.empty() || D[S.back()] < D[i]) S.push_back(i);
		B[i] = 0;
	}
	S.push_back(i);

	B[0] = 1;
	for(i = 1; i < S.size(); i ++){
		t = S[i] - S[i - 1];
		for(j = n; j >= t; j --){
			if(B[j - t]) B[j] = 1;
		}
	}

	cout << (B[n]? "YES" : "NO") << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	for(cin >> t; t --; tc());

	return 0;
}