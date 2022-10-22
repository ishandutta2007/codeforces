#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int b[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[3], sum = 0;
	vector<pair<int, int>>	vec;
	for (int i = 0; i < 3; i++){
		cin >> a[i];
		sum += a[i];
		vec.push_back({a[i], i});
	}

	if (sum % 2 == 1){
		cout << "Impossible" << endl;
		return 0;
	}

	for (; sum; sum -= 2){
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		if (vec[1].first == 0){
			cout << "Impossible" << endl;
			return 0;
		}
		int first = vec[0].second, second = vec[1].second;
		if (first > second)	swap(first, second);
		if (first == 0 && second == 1)	b[0]++;
		if (first == 0 && second == 2)	b[2]++;
		if (first == 1 && second == 2)	b[1]++;
		vec[0].first -= 1;
		vec[1].first -= 1;
	}
	for (int i = 0; i < 3; i++)
		cout << b[i] << " ";
	cout << endl;

	return 0;
}