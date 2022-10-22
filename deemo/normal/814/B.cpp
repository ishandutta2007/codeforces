#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, a[MAXN], b[MAXN];
bool sn[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i], a[i]--;
	for (int i = 0; i < n; i++)	cin >> b[i], b[i]--;

	int mn = 1e9, mx = -1;
	for (int i = 0; i < n; i++)
		if (a[i]^b[i]){
			mn = min(mn, i);
			mx = max(mx, i);
		}

	if (mn == mx){
		for (int j = 0; j < n; j++){
			bool found = 0;
			for (int i = 0; i < n; i++)
				if (i^mn)
					if (a[i] == j){
						found = 1;
						break;
					}

			if (!found){
				a[mn] = j;
				break;
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i]+1 << " ";
		cout << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (i!= mn && i != mx)
			sn[a[i]] = 1;

	int x = -1, y = -1;
	for (int i = 0; i < n; i++)
		if (!sn[i]){
			x = i;
			break;
		}
	for (int i = n-1; ~i; i--)
		if (!sn[i]){
			y = i;
			break;
		}

	int c1 = 0, c2 = 0;
	if (a[mn] != x) c1++;
	if (a[mx] != y) c1++;
	if (b[mn] != x) c2++;
	if (b[mx] != y) c2++;
	if (c1 == 1 && c2 == 1){
		a[mn] = x, a[mx] = y;
	}
	else
		a[mn] = y, a[mx] = x;
	for (int i = 0; i < n; i++)
		cout << a[i]+1 << " ";
	cout << "\n";
	return 0;
}