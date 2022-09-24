#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int C[1010], A[1010], B[1010];
int n;

int getmex()
{
	int i;
	for(i = 0; i <= n; i ++){
		C[i] = 0;
	}
	for(i = 1; i <= n; i ++){
		C[A[i]] = 1;
	}
	for(i = 0; i <= n; i ++){
		if(!C[i]) return i;
	}
}

void print()
{
	int i;
	for(i = 1; i <= n; i ++){
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector <int> V;
	int t, i, j, x;

	for(cin >> t; t --; ){
		cin >> n;
		for(i = 1; i <= n; i ++){
			cin >> A[i];
		}
		V.clear();
		for(; ; ){
			x = getmex();
			if(x == n) break;
			A[x + 1] = x; V.push_back(x + 1);
		}
		for(i = 0; i < n; i ++){
			if(A[i + 1] == i) continue;
			for(x = getmex(); x != i; x = getmex()){
				for(j = 1; j <= n; j ++){
					if(A[j] == i) break;
				}
				A[j] = x; V.push_back(j);
			}
			A[i + 1] = x; V.push_back(i + 1);
		}
		cout << V.size() << "\n";
		for(int &x: V) cout << x << " ";
		cout << "\n";
	}

	return 0;
}