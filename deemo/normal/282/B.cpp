#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	vector<pair<int, int>>	vec(n);
	int dif = 0;
	for (int i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		dif += vec[i].second;
	}

	int i = 0;
	while (dif > 500){
		dif -= vec[i].second;
		dif -= vec[i].first;
		i++;
		cout << "A";
	}
	for (; i < n; i++)
		cout << "G";
	cout << endl;
	return 0;
}