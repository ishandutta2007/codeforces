#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 20;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int mask = 0; mask < 1<<n; mask++){
		int sm = 0;
		for (int j = 0; j < n; j++)
			if (mask>>j&1)
				sm += a[j];
			else
				sm -= a[j];

		sm %= 360;

		sm += 360;
		sm %= 360;
		if (sm == 0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}