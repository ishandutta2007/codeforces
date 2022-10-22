#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second


const int MAXN = 100 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++) cin >> a[i], k = max(k, a[i]);
	while (true){
		int sm = 0;
		for (int i = 0; i < n; i++)
			sm -= a[i], sm += k - a[i];
		if (sm > 0) break;
		k++;
	}
	cout << k << "\n";
	return 0;
}