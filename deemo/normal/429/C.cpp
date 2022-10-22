#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

const int MAXN = 24 + 1;
const int C = 12 + 1;

int n, g[MAXN], cnt;
bool c[1<<C][MAXN], d[1<<C][MAXN];
int cmn[1<<C], dmn[1<<C];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> g[i], cnt += int(g[i] == 1);
	sort(g, g + n, greater<int>());
	if (cnt < n - cnt || g[0] ^ n){
		cout << "NO\n";
		return 0;
	}
	n -= cnt;

	d[0][0] = 1;
	d[0][1] = 1;
	cmn[0] = 200;

	for (int ms = 1; ms < 1<<n; ms++){
		int ind = __builtin_ctz(ms);
		int temp = ms ^ 1<<ind;

		dmn[ms] = cmn[ms] = 200;
		for (int k = 1; k <= cnt; k++){

			for (int sub = temp; ; sub = sub-1&temp){
				for (int w = 1; w <= k; w++)
					if (w + __builtin_popcount(sub) == g[ind] - 1){
						if (w == k && sub == temp)
							d[ms][k] |= cmn[sub] <= w, d[ms][k] |= (dmn[sub] < w) && (w - dmn[sub] + bool(sub) > 1);
						else
							c[ms][k] |= cmn[sub] <= w && ((d[temp^sub][k-w] && temp^sub) || c[temp^sub][k - w])
								, c[ms][k] |= w - dmn[sub] + bool(sub) > 1 && dmn[sub] < w && ((d[temp^sub][k - w] && temp^sub) || c[temp^sub][k - w]);
					}

				if (!sub)	break;
			}

			if (d[ms][k])
				dmn[ms] = min(dmn[ms], k);
			if (c[ms][k])
				cmn[ms] = min(cmn[ms], k);
		}
	}

	if (d[(1<<n)-1][cnt])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}