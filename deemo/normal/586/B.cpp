#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int max_n = 100;

int a[max_n], b[max_n], c[max_n];
int n, t;
vector<int>	vec;

int main(){
	cin >> n;
	for (int i = 0; i < n - 1; i++)	cin >> a[i];
	for (int i = 0; i < n - 1; i++){
		cin >> b[i];
		t += b[i];
	}
	for (int i = 0; i < n; i++)	cin >> c[i];
	
	int sum = 0;
	for (int i = 0; i < n; i++){
		vec.push_back(sum + c[i] + t);
		t -= b[i];
		sum += a[i];
	}
	sort(vec.begin(), vec.end());
	cout << vec[0] + vec[1] << endl;
	return 0;
}