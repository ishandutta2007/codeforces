#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 12;
const int MAXK = 100 + 3;

int n, w[MAXN], cnt[1<<MAXN], cc[1<<MAXN][MAXK];

int conv(string s){
	int ret = 0;
	for (int i = 0; i < n; i++){
		ret <<= 1;
		if (s[i] == '1')
			ret |= 1;
	}
	return ret;
}

int get(int m1, int m2){
	int ret = 0;
	for (int i = 0; i < n; i++)
		if ((m1>>i&1) == (m2>>i&1))
			ret += w[n-1-i];
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) cin >> w[i];
	while (m--){
		string s; cin >> s;
		cnt[conv(s)]++;
	}


	for (int mask = 0; mask < 1<<n; mask++)
		for (int mask2 = 0; mask2 < 1<<n; mask2++){
			int t = get(mask, mask2);
			if (t < MAXK)
				cc[mask2][t] += cnt[mask];
		}
	for (int mask = 0; mask < 1<<n; mask++)
		for (int i = 1; i < MAXK; i++)
			cc[mask][i] += cc[mask][i-1];
	
	while (q--){
		string s; int k;
		cin >> s >> k;
		int m = conv(s);
		cout << cc[m][k] << "\n";
	}
	return 0;
}