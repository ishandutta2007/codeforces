#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5;

int n, a[MAXN], cnt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	while (n--) {
		int x; cin >> x;
		cnt[x]++;
	}

	a[MAXN-1] = 0;
	for (int i = MAXN-2; ~i; i--) {
		if (a[i+1])
			a[i] = 1;
		else {
			if (cnt[i] % 2 == 1)
				a[i] = 1;
			else
				a[i] = 0;
		}
	}
	if (a[0])
		cout << "Conan\n";
	else
		cout << "Agasa\n";
	return 0;
}