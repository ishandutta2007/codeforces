//Nobody could save me now!!!

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n, m;	cin >> n >> m;
	vector<int>	vec;
	for (int i = 0; i < n; i++){
		double temp;
		int x;	cin >> x >> temp;
		int pos = upper_bound(vec.begin(), vec.end(), x) - vec.begin();
		if (pos == vec.size())
			vec.push_back(x);
		else
			vec[pos] = x;
		temp += x;
	}
	cout << n - vec.size() << endl;
	return 0;
}