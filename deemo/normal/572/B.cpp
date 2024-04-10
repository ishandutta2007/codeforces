#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 100;

int n, s;
int cnt[2][MAXN];
vector<pair<int, int>>	vec, sec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	while (n--){
		char ch;	int a, b;	cin >> ch >> a >> b;
		if (ch == 'S')	ch = 0;
		else	ch = 1;
		cnt[ch][a] += b;
	}
	for (int i = 0; i < MAXN; i++)
		if (cnt[0][i])
			vec.push_back({i, cnt[0][i]});
	for (int i = 0; i < MAXN; i++)
		if (cnt[1][i])
			sec.push_back({i, cnt[1][i]});
	sort(vec.begin(), vec.end());
	sort(vec.begin(), vec.begin() + min((int)vec.size(), s), greater<pair<int, int>>());
	sort(sec.begin(), sec.end(), greater<pair<int, int>>());
	for (int i = 0; i < min((int)vec.size(), s); i++)
		cout << "S " << vec[i].first << " " << vec[i].second << endl;
	for (int i = 0; i < min((int)sec.size(), s); i++)
		cout << "B " << sec[i].first << " " << sec[i].second << endl;
	return 0;
}