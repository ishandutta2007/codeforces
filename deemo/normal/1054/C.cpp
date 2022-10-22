#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, a[MAXN], l[MAXN], r[MAXN];
int tl[MAXN], tr[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i];
	for (int i = 0; i < n; i++) cin >> r[i];

	for (int k = n; k; k--){
		int c = 0;
		for (int i = 0; i < n; i++){
			if (a[i])
				c++;
			tl[i] = c;
		}
		c = 0;
		for (int i = n-1; ~i; i--){
			if (a[i])
				c++;
			tr[i] = c;
		}

		for (int i = 0; i < n; i++)
			if (a[i] == 0 && l[i] == tl[i] && r[i] == tr[i])
				a[i] = k;
	}

	for (int i = 0; i < n; i++)
		if (a[i] == 0) {
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}