#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;

int n, q;
ll mark[MAXN];
ll vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	
	while (q--){
		int l, r;	cin >> l >> r;	l--;
		mark[l]++;
		mark[r]--;
	}

	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += mark[i];
		sec[i] = sum;
	}
	sort(sec, sec + n);

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += ll(sec[i]) * ll(vec[i]);
	cout << ans << endl;
	return	0;
}