#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 5e3 + 10;

int n, vec[MAXN];

int solve(int l, int r, int h){
	int mini = 1e9 + 2;
	for (int i = l; i < r; i++)
		mini = min(mini, vec[i]);

	int ret = mini - h, b = l;
	h = mini;

	for (int i = l; i < r; i++)
		if (vec[i] == h){
			if (i - b)
				ret += solve(b, i, h);
			b = i + 1;
		}
	if (b != r)
		ret += solve(b, r, h);

	return	min(ret, r - l);
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	cout << solve(0, n, 0) << endl;
	return	0;
}