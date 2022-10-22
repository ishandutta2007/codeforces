//trying to figure out this life..
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int max_n = 1e4;

int n;
vector<int>	vec(3);
int d[max_n];

int main(){
	cin >> n >> vec[0] >> vec[1] >> vec[2];
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++){
		d[i] = -1;
		if (i >= vec[0] && d[i - vec[0]] != -1)
			d[i] = max(d[i], d[i - vec[0]] + 1);
		if (i >= vec[1] && d[i - vec[1]] != -1)
			d[i] = max(d[i], d[i - vec[1]] + 1);
		if (i >= vec[2] && d[i - vec[2]] != -1)
			d[i] = max(d[i], d[i - vec[2]] + 1);
	}
	cout << d[n] << endl;
	return 0;
}