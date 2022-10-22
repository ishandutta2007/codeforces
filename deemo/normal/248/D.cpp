#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 5e5 + 10;

int n, t, c1, c2, lasth;
string s;
int fs[MAXN];

int get(int x, int l = 0){
	int ret = 0, ls = l;
	bool fl = 0;
	int w = max(lasth, fs[c1 - x]);
	for (int i = l; i <= w; i++){
		ret++;
		if (s[i] == 'S')	x++;
		if (s[i] == 'H')	x--;
		if (x < 0)	fl = 1;

		if (fl && x == 0){
			int z = 2 * (w - i) + (i - ls);
			z = min(z, 2 * (i - ls)) + get(0, i + 1);
			if (i == w)	z = min(z, (i - ls));
			ret += z;
			break;
		}
		if (x >= 0)	ls = i + 1;
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t >> s;
	for (char ch:s)
		if (ch == 'H')
			c1++;
		else if (ch == 'S')
			c2++;
	if (t >= 2 * n - 1){
		cout << max(0, c1 - c2) << endl;
		return	0;
	}

	int cn = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'H')
			lasth = max(lasth, i);
		else if (s[i] == 'S')
			fs[++cn] = i;
	}
	if (t < lasth + 1){
		cout << -1 << endl;
		return	0;
	}

	int b = max(0, c1 - c2), e = c1, ret;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (get(mid) <= t){
			ret = mid;
			e = mid - 1;
		}
		else	b = mid + 1;
	}
	cout << ret << endl;
	return 0;
}