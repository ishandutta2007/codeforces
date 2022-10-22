#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(n);
	iota(vec.begin(), vec.begin() + n, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << j * n + (vec[j] + 1) << " ";
		cout << "\n";
		rotate(vec.begin(), vec.begin() + 1, vec.end());
	}
	return 0;
}