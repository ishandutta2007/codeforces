#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;

int n, q;
int vec[MAXN];
int d[MAXN], c[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)	cin >> vec[i];

	for (int i = n - 1; i >= 0; i--){
		if (i == n - 1 || vec[i] < vec[i + 1])
			c[i] = 1;
		else
			c[i] = 1 + c[i + 1];

		if (i == n - 1 || vec[i] > vec[i + 1])
			d[i] = 1;
		else
			d[i] = 1 + d[i + 1];
	}

	while (q--){
		int l, r;	cin >> l >> r;	l--;
		int x = d[l];
		l += x;
		
		bool ret = 0;
		if (l >= r)
			ret = 1;
		else{
			x = c[l];
			l += x;
			if (l >= r)	ret = 1;
		}
		if (ret)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}