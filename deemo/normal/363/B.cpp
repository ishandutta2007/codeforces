#include<iostream>

using namespace std;

const int max_n = 2e5;

int n, k;
int a[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b = 0, e = 0, mini = 1e9, ind = -1, sum = 0;
	for (int i = 0; i <= n - k; i++){
		while (e - i < k){
			sum += a[e];
			e++;
		}
		if (sum < mini){
			mini = sum;
			ind = i;
		}
		sum -= a[i];
	}
	cout << ind + 1 << endl;
	return 0;
}