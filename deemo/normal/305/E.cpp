#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 5e3 + 7;

int n, gr[MAXN];
bool mark[MAXN];
string s;
vector<pair<int, int>>	vec;

int main(){
	cin >> s;
	n = s.size();
	for (int i = 1; i < n - 1;){
		if (s[i - 1] != s[i + 1]){
			i++;
			continue;
		}
		int j = i;
		while (j < n - 1 && s[j - 1] == s[j + 1])	j++;
		if (j != i)	vec.push_back({i, j - 1});
		i = j + 1;
	}

	for (int i = 3; i < MAXN; i++){
		memset(mark, 0, sizeof(mark));
		for (int j = 2; j < i; j++)
			mark[gr[j - 1] ^ gr[i - j]] = 1;

		for (int j = 0; j < MAXN; j++)
			if (mark[j] == 0){
				gr[i] = j;
				break;
			}
	}

	int xx = 0;
	for (pair<int, int>	v:vec)
		xx ^= gr[v.second - v.first + 3];

	if (xx == 0)
		cout << "Second\n";
	else{
		cout << "First\n";
		bool found = 0;
		for (pair<int, int>	v:vec){
			int sz = v.second - v.first + 3;
			for (int j = 2; j < sz; j++)
				if ((xx ^ gr[sz] ^ (gr[j - 1] ^ gr[sz - j])) == 0){
					cout << v.first + j - 1 << "\n";
					found = 1;
					break;
				}
			if (found)	break;
		}
	}
	return	0;
}