#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<functional>
#include<cassert>

using namespace std;

const int MAXN = 3e5 + 30;
const int LOG = 20;

int n, lc[LOG][MAXN], ss[MAXN];
pair<string, int>	s[MAXN];
pair<int, int>	sec[MAXN];
vector<pair<int, int>>	ans;
set<pair<int, pair<int, int>>>	st;
bool pic[MAXN];
set<int>	rem;

int lcp(int a, int b){
	int ret = 0;
	for (int i = 0; i < min(s[a].first.size(), s[b].first.size()); i++, ret++)
		if (s[a].first[i] != s[b].first[i])	break;
	return	ret;
}

void init(){
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < 2 * n; i++)
			if (i + (1 << (w - 1)) >= 2 * n - 1)
				lc[w][i] = lc[w - 1][i];
			else
				lc[w][i] = min(lc[w - 1][i], lc[w - 1][i + (1<< (w - 1))]);

	for (int i = 1, j = 0; i < MAXN; i += (1<<j), j++)
		for (int w = i; w < MAXN && w < i + (1 << j); w++)
			ss[w] = j;
}

int gla(int l, int r){
	return min(lc[ss[r - l]][l], lc[ss[r - l]][r - (1 << ss[r - l])]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i].first, s[i].second = i;
	for (int i = 0; i < n; i++)	cin >> s[i + n].first, s[i + n].second = n + i;
	sort(s, s + 2 * n);
	for (int i = 0; i < 2 * n - 1; i++){
		lc[0][i] = lcp(i, i + 1);
		if (s[i].second/n != s[i + 1].second/n)
			st.insert({lc[0][i], {i, i + 1}});
	}
	for (int i = 0; i < 2*n; i++)
		rem.insert(i);
	init();

	int ret = 0;
	while (rem.size()){
		//assert(st.size());

		pair<int, int>	ind;
		bool x;
		{
			auto it = st.end();	it--;
			ind = it->second;
			if (pic[ind.first] || pic[ind.second]){
				st.erase(it);
				continue;
			}

			pic[ind.first] = pic[ind.second] = 1;
			ret += it->first;
			x = s[ind.first].second >= n;
			st.erase(it);

			ans.push_back({s[ind.first].second, s[ind.second].second});
		}

		rem.erase(ind.first);
		rem.erase(ind.second);
		auto it = rem.lower_bound(ind.first);
		if (it != rem.begin()){
			it--;
			int f =*it;
			it = rem.lower_bound(ind.second);
			if (it != rem.end())
				if (s[f].second/n != s[*it].second/n)
					st.insert({gla(f, *it), {f, *it}});
		}
	}

	cout << ret << "\n";
	for (auto v:ans){
		if (v.first > v.second)
			swap(v.first, v.second);
		cout << v.first + 1 << " " << v.second - n + 1 << "\n";
	}
	return	0;
}