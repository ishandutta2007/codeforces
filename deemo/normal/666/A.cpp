#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
bool d[2][MAXN];
string s;
vector<string>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	if (n <= 6){
		cout << "0\n";
		return 0;
	}

	d[0][n - 2] = 1;
	d[1][n - 3] = 1;
	for (int i = n - 2; i >= 5; i--){
		if (i + 2 <= n){
			d[0][i] |= d[1][i + 2];
			if (d[0][i + 2] && s.substr(i + 2, 2) != s.substr(i, 2))	d[0][i] = 1;
			if (d[0][i])
				vec.push_back(s.substr(i, 2));
		}
		if (i + 3 <= n){
			d[1][i] |= d[0][i + 3];
			if (d[1][i + 3] && s.substr(i + 3, 3) != s.substr(i, 3))	d[1][i] = 1;
			if (d[1][i])
				vec.push_back(s.substr(i, 3));
		}
	}

	sort(vec.begin(), vec.end());
	int sz = unique(vec.begin(), vec.end()) - vec.begin();
	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << vec[i] << "\n";
	return 0;
}