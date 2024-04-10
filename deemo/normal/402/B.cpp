#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, k, h[MAXN];
bool mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> h[i];
	int mx = 0, ind = -1;
	for (int i = 0; i < n; i++)
		if (h[i] - i * k > 0){
			int ret = 1, prv = h[i], t = k;
			for (int j = i + 1; j < n; j++, t += k)
				if (h[j] - t == prv){
					ret++;
					prv = h[j];
					t = 0;
				}
			if (ret > mx)
				mx = ret, ind = i;
		}

	cout << n - mx << "\n";
	mark[ind] = 1;
	int prv = h[ind], t = k;
	for (int i = ind + 1; i < n; i++, t += k)
		if (h[i] - t == prv){
			mark[i] = 1;
			t = 0;
			prv = h[i];
		}

	for (int i = 0; i < n; i++)
		if (!mark[i]){
			int x = (i - ind) * k + h[ind];	
			x = x - h[i];
			if (x > 0)
				cout << "+ " << i + 1 << " " << x << "\n";
			else if (x < 0)
				cout << "- " << i + 1 << " " << -x << "\n";
		}
	return	0;
}