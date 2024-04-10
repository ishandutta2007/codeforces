#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	vector<int>	vec;
	for (int i = 1; i <= n; i++){
		int x = 1;
		while (vec.size() && vec.back() == x)	x++, vec.pop_back();
		vec.push_back(x);
	}
	for (int u:vec)
		cout << u << " ";
	cout << endl;
	return	0;
}