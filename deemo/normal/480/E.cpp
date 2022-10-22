#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<deque>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 2e3 + 4;
int n, m, q;
set<pair<int, int>>	st;
multiset<int>	ss, tt;
char c[MAXN][MAXN];
int d[MAXN][MAXN], dn[MAXN][MAXN], ri[MAXN][MAXN], ans[MAXN];
pair<int, int>	query[MAXN];

pair<int, int>	get(int x, int y){
	auto it = st.lower_bound({x, y});
	int l, r;

	if (it != st.end() && it->first == x)
		r = it->second;
	else
		r = m;

	it = st.upper_bound({x, y});
	if (it != st.begin()){
		it--;
		if (it->first == x)	l = it->second + 1;
		else	l = 0;
	}
	else	l = 0;
	return	{l, r};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++){
			c[i][j] = temp[j];
			if (c[i][j] == 'X')	st.insert({i, j});
		}
	}
	for (int i = 0; i < q; i++){
		cin >> query[i].first >> query[i].second;	
		query[i].first--, query[i].second--;
		st.insert(query[i]);
		c[query[i].first][query[i].second] = 'X';
	}

	int cur = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			if (c[i][j] != 'X'){
				dn[i][j] = 1 + dn[i + 1][j];
				ri[i][j] = 1 + ri[i][j + 1];

				d[i][j] = d[i][j + 1] + 1;
				while (d[i][j]){
					if (dn[i][j] >= d[i][j] && ri[i + d[i][j] - 1][j] >= d[i][j])	break;
					d[i][j]--;
				}
				cur = max(cur, d[i][j]);
			}

	for (int i = q - 1; i >= 0; i--){
		pair<int, int>	v = query[i];
		st.erase(v);
		c[v.first][v.second] = '.';
		ans[i] = cur;
		
		bool fl = 1;
		while (cur < min(n, m) && fl){
			fl = 0;
			ss.clear();
			tt.clear();
			cur++;

			for (int j = max(0, v.first - cur + 1); j < v.first + cur && j < n; j++){
				pair<int, int>	temp = get(j, v.second);
				ss.insert(temp.first);
				tt.insert(temp.second);
				if (ss.size() > cur)	
					ss.erase(ss.find(get(j - cur, v.second).first)), tt.erase(tt.find(get(j - cur, v.second).second));

				if (ss.size() == cur){
					auto it = ss.end();	it--;	int maxi = *it;
					it = tt.begin();	int mini = *it;
					if (mini - maxi >= cur){
						fl = 1;
						break;
					}
				}
			}

			if (!fl)	cur--;
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return	0;	
}