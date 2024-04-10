#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e7 + 100;

ll n, x, y, d[MAXN];

int main(){
	cin >> n >> x >> y;
	memset(d, 63, sizeof(d));
	d[1] = x;
	d[0] = 0;
	for (int i = 2; i < MAXN; i <<= 1){
		int j = i>>1;
		for (int w = j + 1; w <= i; w++){
			d[w] = min(d[w], d[w - 1] + x);
			if (!(w & 1))
				d[w] = min(d[w], d[w>>1] + y);
		}
		for (int w = i - 1; w > j; w--)
			d[w] = min(d[w], d[w + 1] + x);
	}

	cout << d[n] << "\n";
	return 0;
}