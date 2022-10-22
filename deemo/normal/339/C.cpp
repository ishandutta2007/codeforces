#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 1e3 + 10;

string s;
int n;
bool d[max_n][20][20];
pair<int, int> par[max_n][20][20];

void show_Ans(int rem , int j, int k){
	if (rem > 1)
		show_Ans(rem - 1, par[rem][j][k].first, par[rem][j][k].second);
	cout << k << " ";
}

int main(){
	cin >> s >> n;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '1')
			d[1][i + 1][i + 1] = 1, par[1][i + 1][i + 1] = {-1, -1};

	for (int i = 1; i < n; i++)
		for (int j = 1; j < 11; j++)
			for (int k = 1; k < 11; k++){
				if (d[i][j][k] == 0)	continue;
				for (int w = 1; w < 11; w++){
					if (s[w - 1] == '0' || w == k || w <= j)	continue;
					d[i + 1][w - j][w] = 1;
					par[i + 1][w - j][w] = {j, k};
				}
			}

	for (int j = 1; j < 11; j++)
		for (int k = 1; k < 11; k++)
			if (d[n][j][k]){
				cout << "YES" << endl;
				show_Ans(n, j, k);
				cout << endl;
				return 0;
			}

	cout << "NO" << endl;
	return 0;
}