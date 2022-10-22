//second chances?!

#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;	cin >> n;
	vector<int>	vec(n);
	for (int i = 0; i < n; i++)	cin >> vec[i];
	int ans = 1;
	for (int i = n - 2; i >= 0; i--)
		if (vec[i] < vec[i + 1])
			ans++;
		else
			break;
	cout << n - ans << endl;
	return 0;
}