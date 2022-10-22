#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, k, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (k == n)
		cout << a[n-1] << "\n";
	else{
		if (k == 0){
			if (a[0] > 1)
				cout << "1\n";
			else
				cout << "-1\n";
		}
		else{
			if (a[k-1] != a[k])
				cout << a[k-1] << "\n";
			else
				cout << "-1\n";
		}
	}
	return 0;
}