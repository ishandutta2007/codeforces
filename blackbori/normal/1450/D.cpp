#include <bits/stdc++.h>

using namespace std;

vector <int> S;
vector <int> V[303030];
bool X[303030], C[303030];
int A[303030], L[303030], R[303030], D[303030];
int n;

void tc()
{
	int i, m, s;

	cin >> n;

	S.clear();
	for(i = 1; i <= n; i ++){
		cin >> A[i]; L[i] = 1; R[i] = n;
		for(; !S.empty() && A[S.back()] > A[i]; S.pop_back()){
			R[S.back()] = i - 1;
		}
		if(!S.empty()) L[i] = S.back() + 1;
		S.push_back(i);
		D[i] = 0; C[i] = 0;
		V[i].clear();
	}

	for(i = 1; i <= n; i ++){
		V[R[i] - L[i] + 1].push_back(A[i]);
	}
	m = 0; s = 0;
	for(i = n; i >= 1; i --){
		for(int &t: V[i]){
			if(!C[t]) s ++;
			C[t] = 1;
			m = max(m, t);
		}

		if(m == n - i + 1 && s == n - i + 1) X[i] = 1;
		else X[i] = 0;
	}
	for(i = 1; i <= n; i ++) cout << X[i];
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for(; t --; ){
		tc();
	}
}