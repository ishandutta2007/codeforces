#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 25 + 2;
const int C = 12;

int n, vec[3][MAXN];
map<pair<int, int>, pair<int, int>>	mp;
map<pair<int, int>, int>	mx;

void proc(int m1, int m2){
	int a0 = 0, a1 = 0, a2 = 0;
	for (int i = 0; i < min(n, C); i++){
		a0 += vec[0][i], a1 += vec[1][i], a2 += vec[2][i];
		if (((m1 >> i) & 1) == 0)	a0 -= vec[0][i];
		else if (((m2 >> i) & 1) == 0)	a1 -= vec[1][i];
		else a2 -= vec[2][i];
	}	
	if (mp.count({a1 - a0, a2 -a1}) == 0 || mx[{a1 - a0, a2 - a1}] < a0){
		mp[{a1 - a0, a2 - a1}] = {m1, m2};
		mx[{a1 - a0, a2 - a1}] = a0;
	}
}	

pair<pair<int, int>, int> check(int m1, int m2){
	int a0 = 0, a1 = 0, a2 = 0;
	for (int i = 0; i < n - C; i++){
		a0 += vec[0][i + C], a1 += vec[1][i + C], a2 += vec[2][i + C];
		if (((m1 >> i) & 1) == 0)	a0 -= vec[0][i + C];
		else if (((m2 >> i) & 1) == 0)	a1 -= vec[1][i + C];
		else a2 -= vec[2][i + C];
	}	
	if (mp.count({-(a1 - a0), -(a2 - a1)}))	return	{mp[{-(a1 - a0), -(a2 - a1)}], a0 + mx[{-(a1 - a0), -(a2 - a1)}]};
	return	{{-1, -1}, -1e9 - 5};
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)	
		for (int j = 0; j < 3; j++)	cin >> vec[j][i];
	for (int i = 0; i < (1 << min(n, C)); i++)
		for (int j = i; ; j = (j - 1) & i){
			proc(i, j);
			if (j == 0)	break;
		}
	//return	0;
	if (mp.count({0, 0}) && n <= C){
		auto s = mp[{0, 0}];
		for (int i = 0; i < n; i++)
			if (((s.first >> i) & 1) == 0)	cout << "MW\n";
			else if (((s.second >> i) & 1) == 0)	cout << "LW\n";
			else cout << "LM\n";
		return	0;
	}

	if (n > C){
		pair<int, int>	ans1(-1, -1), ans2(-1, -1);
		int xx = -1e9;
		for (int i = 0; i < (1 << (n - C)); i++)
			for (int j = i; ; j = (j - 1) & i){
				auto s = check(i, j);
				if (s.second > xx){
					xx = s.second;
					ans1 = s.first;
					ans2 = {i, j};
				}
				if (j == 0)	break;
			}

		if (ans1.first != -1){
			for (int i = 0; i < C; i++)
				if (((ans1.first >> i) & 1) == 0)	cout << "MW\n";
				else if (((ans1.second >> i) & 1) == 0)	cout << "LW\n";
				else cout << "LM\n";

			for (int i = 0; i < n-C; i++)
				if (((ans2.first >> i) & 1) == 0)	cout << "MW\n";
				else if (((ans2.second >> i) & 1) == 0)	cout << "LW\n";
				else cout << "LM\n";
			return	0;
		}
	}

	cout << "Impossible\n";
	return	0;
}