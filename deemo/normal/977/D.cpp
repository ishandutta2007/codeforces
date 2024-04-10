#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 10;

int n;
ll a[MAXN];

ll get(ll x){
	ll ans = 0;
	while (x % 3 == 0)
		x /= 3, ans++;
	return ans;
}

bool cmp(ll a, ll b){
	if (get(a) != get(b))
		return get(a) > get(b);
	return a < b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}