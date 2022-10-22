#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int cnt[MAXN], ss[MAXN], xx[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	while (n--){
		int x;	cin >> x;
		cnt[x]++;
	}

	ss[0] = 1;
	for (int i = 1; i < MAXN; i++){
		ss[i] = ss[i - 1]<<1;
		if (ss[i] >= MOD)
			ss[i] -= MOD;
	}

	for (int i = MAXN-1; i; i--){
		int c = 0;
		for (int j = i; j < MAXN; j += i)
			c += cnt[j];
		xx[i] = ss[c]-1;
		if (xx[i] < 0) xx[i] += MOD;

		for (int j = i<<1; j < MAXN; j += i){
			xx[i] -= xx[j];
			if (xx[i] < 0) xx[i] += MOD;
		}
	}
	cout << xx[1] << "\n";
	return 0;
}