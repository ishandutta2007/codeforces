#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 3e3 + 10;

int a[2][3], b[7], c[2][3];
int cnt[3];

void solve() {
	for (int w = 0; w < 2; w++)
		for (int i = 0; i < 3; i++)
			cin >> a[w][i];
	for (int i = 0; i < 7; i++) cin >> b[i];
	cnt[0] = b[0] + b[1] + b[2] + b[3];
	cnt[1] = b[0] + b[1] + b[4] + b[5];
	cnt[2] = b[0] + b[2] + b[4] + b[6];
	for (int i = 0; i < 3; i++)
		if (a[0][i] + a[1][i] < cnt[i]){
			cout << "-1\n";
			return;
		}
	cnt[0] = b[1] + b[2];
	cnt[1] = b[1] + b[4];
	cnt[2] = b[2] + b[4];

	for (int k = 0; k <= b[4]; k++) //math
		for (int i = 0; i <= b[1]; i++) //pe
			if (i+k <= a[0][1] && cnt[1] - (i+k) <= a[1][1])
				for (int j = 0; j <= b[2]; j++) //pr
					if (j+k <= a[0][2] && cnt[2] - (j+k) <= a[1][2])
						if (i+j <= a[0][0] && cnt[0] - (i+j) <= a[1][0]) {
							memcpy(c, a, sizeof(a));
							c[0][1] -= i+k;
							c[1][1] -= cnt[1] - (i+k);
							c[0][2] -= j+k;
							c[1][2] -= cnt[2] - (j+k);
							c[0][0] -= i+j;
							c[1][0] -= cnt[0] - (i+j);
							if (min({c[0][0], c[0][1], c[0][2]}) + min({c[1][0], c[1][1], c[1][2]}) < b[0]) continue;
							int g = min({c[0][0], c[0][1], c[0][2], b[0]});
							cout << g << " ";
							c[0][0] -= g;
							c[0][1] -= g;
							c[0][2] -= g;
							int g1 = min(c[0][0], b[3]);
							
							cout << i << " " << j << " " << g1 << " " << k << " " << min(c[0][1], b[5]) << " " << min(c[0][2], b[6]) << "\n";
							return;
						}
	cout << "-1\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}