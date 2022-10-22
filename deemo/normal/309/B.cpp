//I can't hold on to me..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 10;
const int LOG = 20 + 2;

int n, row, c;
string s[MAXN];
int ri[LOG][MAXN];

int get(int ind){
	int x = row, tind = ind;
	for (int i = LOG - 1; i >= 0; i--)
		if (x >= (1 << i)){
			x -= (1 << i);
			ind = ri[i][ind];
		}
	return	ind - tind;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> row >> c;	
	for (int i = 0; i < n; i++)	cin >> s[i];

	{
		int r = 0, sz = 0;
		for (int i = 0; i < n; i++){
			if (r < i)	r = i;
			while (r < n && sz + 1 * bool(sz) + (int)s[r].size() <= c)	sz += 1 * bool(sz) + (int)s[r++].size();

			ri[0][i] = r;
			if (r > i)	sz = max(0, sz - (1 + (int)s[i].size()));
		}
	}

	for (int i = 1; i < LOG; i++){
		ri[i - 1][n] = n;
		for (int j = 0; j < n; j++)
			ri[i][j] = ri[i - 1][ri[i - 1][j]];
	}

	int ans = 0, ind = -1;
	for (int i = 0; i < n; i++){
		int sz = get(i);
		if (sz > ans){
			ans = sz;
			ind = i;
		}
	}
	if (ind >= 0){
		int i = ind;
		while (i < ind + ans){
			for (int j = i; j < ri[0][i]; j++)
				if (j != ri[0][i] - 1)
					cout << s[j] << " ";
				else
					cout << s[j] << "\n";
			i = ri[0][i];
		}
	}

	return	0;
}