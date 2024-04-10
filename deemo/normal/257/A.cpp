#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 50 + 5;

int n, m, k;
int vec[MAXN];

int main(){
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	if (k >= m){
		cout << 0 << endl;
		return 0;
	}
	sort(vec, vec + n);
	reverse(vec, vec + n);
	int sum = 0;
	for (int i = 0; i < min(k, n); i++){
		sum += vec[i];
		if (sum + (k - i - 1) >= m){
			cout << i + 1 << endl;
			return 0;
		}
	}

	for (int i = min(n, k); i < n; i++){
		sum += vec[i] - 1;
		if (sum >= m){
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}