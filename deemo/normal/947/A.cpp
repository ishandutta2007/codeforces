#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int d[MAXN];
bool pr[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(d, 63, sizeof(d));
	for (int i = 2; i < MAXN; i++)
		if (!pr[i])
			for (int j = i+i; j < MAXN; j += i)
				pr[j] = true, d[j] = j - i + 1;
	int n; cin >> n;
	int ans = 1e9;
	for (int i = 2; i <= n; i++)
		if (!pr[i] && n % i == 0){
			for (int j = n - i+1; j <= n; j++)
				if (j >= 4)
					ans = min(ans, d[j]);
		}
	cout << ans << "\n";
	return 0;
}