#include <bits/stdc++.h>

using namespace std;

vector <int> V[303030];
int A[303030];
int tc, n, k, m, i, a, t, j;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	for(; tc --; ){
		cin >> n;
		for(i = 1; i <= n; i ++){
			V[i].clear();
		}
		for(i = 1; i <= n; i ++){
			cin >> a;
			V[a].push_back(i);
			A[i] = -1;
		}
		k = n;
		for(i = 1; i <= n; i ++){
			m = 0; t = 0;
			for(int &j: V[i]){
				m = max(m, j - t);
				t = j;
			}
			m = max(m, n + 1 - t);
			for(; k >= m; k --) A[k] = i;
		}
		for(i = 1; i <= n; i ++){
			cout << A[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}