#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(2 * n - 1);
	int sum = 0, cnt = 0;
	for (int i = 0; i < 2 * n - 1; i++){
		cin >> vec[i];
		if (vec[i] < 0){
			cnt++;
			vec[i] = -vec[i];
		}
		sum += vec[i];
	}
	sort(vec.begin(), vec.end());
	if (n % 2 == 1){
		cout << sum << endl;
		return 0;
	}
	
	if (cnt % 2 == 0){
		cout << sum << endl;
		return 0;
	}
	cout << sum - 2 * vec[0] << endl;
	return 0;
}