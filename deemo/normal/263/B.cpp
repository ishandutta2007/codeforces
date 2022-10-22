#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, k;	cin >> n >> k;
	int vec[100];
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	if (k > n){
		cout << -1 << endl;
		return	0;
	}
	int x = vec[n - k];
	cout << x << " " << x << endl;
	return 0;
}