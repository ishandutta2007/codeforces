//When everything, everything, everything you touch turns to gold!

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e3 + 10;

int n, m;
vector<pair<int, int>>	ans, vec, sec;
ld maxi = 0;
bool mark[MAXN][MAXN];

ld dis(ld a, ld b, ld c, ld d){
	ld ret = (a - c) * (a - c);
	ret += (b - d) * (b - d);
	return	ret;
}

ld get(vector<pair<int, int>>	t){
	ld ret = 0;
	for (int i = 0; i < 3; i++)
		ret += dis(t[i].first, t[i].second, t[i + 1].first, t[i + 1].second);
	return	ret;
}

void gen(int rem){
	if (rem == 0){
		if (maxi < get(sec)){
			maxi = get(sec);
			ans.assign(sec.begin(), sec.end());
		}
		return;
	}

	for (pair<int, int>	v:vec)
		if (!mark[v.first][v.second]){
			mark[v.first][v.second] = 1;
			sec.push_back(v);
			gen(rem - 1);
			sec.pop_back();
			mark[v.first][v.second] = 0;
		}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if ((i < 4 && j < 4) || (n - i < 4 && m - j < 4))
				vec.push_back({i, j});
			else if ((n - i < 3 && j < 3) || (m - j < 3 && i < 3))
				vec.push_back({i, j});
	
	sort(vec.begin(), vec.end());
	gen(4);

	for (pair<int, int>	v:ans)
		cout << v.first << " " << v.second << "\n";
	return	0;
}