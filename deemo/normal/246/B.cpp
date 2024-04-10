#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	if (n == 1){
		cout << 1 << endl;
		return 0;
	}

	int sum = 0;
	for (int i = 1; i < n - 1; i++)
		sum += vec[i] - vec[0];
	sum += vec[n - 1] - vec[0];
	if (sum % n == 0)
		cout << n << endl;
	else
		cout << n - 1 << endl;
	return 0;
}