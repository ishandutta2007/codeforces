#include <bits/stdc++.h>

using namespace std;
using pii = pair <int, int>;

vector <int> V[101010];
vector <pii> S, T;
int D[101010], C[101010], A[101010];
int n, x, y;

void tc()
{
	int i, j, c, t, m;

	cin >> n >> x >> y;

	S.clear(); T.clear();
	for(i = 1; i <= n + 1; i ++){
		V[i].clear(); C[i] = 0;
	}

	for(i = 1; i <= n; i ++){
		cin >> D[i]; C[D[i]] ++;
		V[D[i]].push_back(i);
	}

	for(i = 1; i <= n + 1; i ++){
		S.emplace_back(C[i], i);
	}

	sort(S.rbegin(), S.rend());

	c = S[n].second;
	for(i = 1; i <= n; i ++){
		A[i] = c;
	}

	m = 0;
	for(i = 0, j = 0; i < y - x; i ++){
		S[j].first --; t = S[j].second;
		m = max(m, C[t] - S[j].first);
		T.emplace_back(t, V[t][S[j].first]);
//		cout << t << " " << V[t][S[j].first] << "\n";
		j ++; if(S[j].first == 0) j = 0;
	}

	int f = 0;
	if(m + m > y - x){
		if(y < n && m + m - 1 == y - x && j == 1){
			S[j].first --; t = S[j].second; f = 1;
			T.emplace_back(t, V[t][S[j].first]);
		}
		else{
			cout << "NO\n";
			return;
		}
	}

	sort(T.begin(), T.end());

	for(i = 0, j = m; i < y - x; i ++){
		A[T[i].second] = D[T[j].second];
		j = (j + 1) % (int)T.size();
	}
	if(f) A[T[i].second] = 0;

	cout << "YES\n";

	for(i = 1; i <= n; i ++){
		if(x && A[i] == c){
			A[i] = D[i]; x --;
		}
		else if(A[i] == 0) A[i] = c;
		cout << A[i] << " ";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	for(cin >> t; t --; tc());

	return 0;
}