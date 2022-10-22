#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 500 + 10;

int n, a[MAXN], m, b[MAXN], sz;
pair<int, char>	ans[MAXN];
int sm1, sm2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i], sm1 += a[i];
	cin >> m;
	for (int i = 0; i < m; i++)	cin >> b[i], sm2 += b[i];
	if (sm1 ^ sm2){
		cout << "NO\n";
		return 0;
	}

	for (int i = n; i > m; i--){
		int j = 0;
		while (a[j] == b[j])	j++;

		int w = j, sm = 0;
		while (sm < b[j])
			sm += a[w++];
		if (sm > b[j]){
			cout << "NO\n";
			return 0;
		}

		if (*min_element(a + j, a + w) == *max_element(a+j, a+w)){
			cout << "NO\n";
			return 0;
		}

		int mx = *max_element(a+j, a+w), id;
		for (int z = j; z < w; z++)
			if (a[z] == mx && ((z - 1 >= j && a[z - 1] < mx) || (z + 1 < w && a[z + 1] < mx))){
				id = z;
				break;
			}
		if (id - 1 >= j && a[id - 1] < mx){
			ans[sz++] = {id, 'L'};
			a[id] += a[id - 1];
			for (int z = id - 1; z + 1 < i; z++)
				a[z] = a[z + 1];
		}
		else{
			ans[sz++] = {id, 'R'};
			a[id] += a[id + 1];
			for (int z = id+1; z + 1 < i; z++)
				a[z] = a[z + 1];
		}
	}

	cout << "YES\n";
	for (int i = 0; i < sz; i++)
		cout << ans[i].F+1 << " " << ans[i].S << "\n";
	return 0;
}