#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A[55];
int n;

void tc()
{
	int i; ll s;
	cin >> n;

	for(i = 0; i < n; i ++){
		cin >> A[i];
	}

	sort(A, A + n);

	for(i = 0, s = 0; i < n; i ++){
		s += A[i];
		if(s == 0) break;
	}

	if(i == n){
		cout << "YES\n";
		for(i = 0; i < n; i ++){
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}

	reverse(A, A + n);

	for(i = 0, s = 0; i < n; i ++){
		s += A[i];
		if(s == 0) break;
	}

	if(i == n){
		cout << "YES\n";
		for(i = 0; i < n; i ++){
			cout << A[i] << " ";
		}
		cout << "\n";
		return;
	}

	cout << "NO\n";
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

	return 0;
}