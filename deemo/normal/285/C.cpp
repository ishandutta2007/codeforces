#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 3e5 + 30;

int n, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += abs(vec[i] - (i + 1));
	cout << ans << endl;
	return 0;
}