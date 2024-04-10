#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2e3 + 20;

int n, k, vec[MAXN];

int main(){
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		ans = max(ans, vec[i] - 1);
	}
	sort(vec, vec + n);

	int cur = 1;
	for (int i = 0; i < n;){
		int rem = n - i;
		int z = rem/k + bool(rem % k);
		ans += (z - 1) * 2 * (vec[i] - cur) + (vec[i] - cur);
		int j = i;
		cur = vec[i];
		while (j < n && vec[j] == vec[i])	j++;
		i = j;
	}
	cout << ans << endl;
	return	0;
}