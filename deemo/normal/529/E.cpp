#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 5e3 + 10;
const int MAXK = 20 + 3;
const int MAXX = 1e7 + 10;
const int INF = 100 + 2;

int n, k, vec[MAXN];
bool sn[MAXX + 100];

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++)	
		cin >> vec[i], sn[vec[i]] = 1;
	int q;	cin >> q;
	while (q--){
		int x, ret = INF;	cin >> x;
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= k && j * vec[i] <= x; j++){
				int rem = x - j * vec[i];
				if (rem == 0){
					ret = min(ret, j);
					continue;
				}

				for (int w = 1; w <= k - j; w++)
					if (rem % w == 0){
						int z = rem/ w;
						if (z >= MAXX || z >= vec[i] || !sn[z])	continue;
						ret = min(ret, j + w);
					}	
			}

		if (ret == INF)	ret = -1;
		cout << ret << "\n";
	}
	return	0;
}