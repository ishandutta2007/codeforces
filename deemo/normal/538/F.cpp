#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 10;
const int SQRT = 450;
const int LOG = 19;

int n, val[MAXN], mk[MAXN], ans[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> val[i];

	for (int v = 2; v <= n; v++){
		for (int i = 1; i <= min(SQRT, n - 1); i++){
			int p = (v - 1)/ i + bool((v-1) % i);
			if (val[p] > val[v])	ans[i]++;
		}

		for (int i = n - 1; i > SQRT;){
			int j, xx = (v - 1)/ i + bool((v - 1) % i);
			j = (v-1)/ xx + bool((v-1) % xx);

			j = max(SQRT + 1, j);
			if (val[xx] > val[v])
				mk[j]++, mk[i + 1]--;
			i = j - 1;
		}
	}

	int ss = 0;
	for (int i = 1; i < n; i++){
		ss += mk[i];
		cout << ss + ans[i] << " ";
	}
	cout << "\n";
	return	0;
}