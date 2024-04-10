#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	int i = 3;
	while (i < n && a[i] == a[2]) i++;
	if (a[2] == a[0])
		cout << 1ll*i*(i-1)*(i-2)/6 << "\n";
	else if (a[1] == a[2])
		cout << 1ll*(i-1)*(i-2)/2 << "\n";
	else
		cout << i-3+1 << "\n";
	return 0;
}