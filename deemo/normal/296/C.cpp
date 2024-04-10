#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 20;

int n, m, k;
ll a[MAX];
pair<int, int>	b[MAX];
ll c[MAX];
ll cnt[MAX];
ll mark[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < m; i++)	cin >> b[i].first >> b[i].second >> c[i];
	while (k--){
		int l, r;	cin >> l >> r;	l--;
		mark[l]++;
		mark[r]--;
	}

	ll z = 0;
	for (int i = 0; i < m; i++){
		z += mark[i];
		cnt[i] = z;
	}
	
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < m; i++){
		int l = b[i].first - 1, r = b[i].second;
		mark[l] += cnt[i] * c[i];
		mark[r] -= cnt[i] * c[i];
	}	

	z = 0;
	for (int i =0 ; i < n; i++){
		z += mark[i];
		cout << a[i] + z << " ";
	}
	cout << endl;
	return 0;
}