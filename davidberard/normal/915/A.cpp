#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	int choice = -1;
	for(int i=n-1;i>=0 && choice == -1;--i) {
		if(k%a[i] == 0)
			choice = i;
	}

	cout << k/a[choice] << endl;

	
	
	return 0;
}