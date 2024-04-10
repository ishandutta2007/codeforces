#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	int n, m;	cin >> n >> m;
	bool fl = 0;
	if (n > m){
		swap(n, m);
		fl = 1;
	}
	vector<pair<int, int>>	vec;
	for (int i = n; i >= 0; i--)
		vec.push_back({i, (n - i)});

	cout << vec.size() << endl;
	for (pair<int, int>	temp:vec)
		if (!fl)
			cout << temp.first << " " << temp.second << endl;
		else
			cout << temp.second << " " << temp.first << endl;
	return 0;
}