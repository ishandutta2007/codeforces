#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 50;
const int INF = 1e9 + 5;

int n, q, k;
int cnt[200][200], tm[200];
string s;
set<pair<pair<int, int>, int>>	st;

void insert(int l, int r, char ch){
	set<pair<pair<int, int>, int>>::iterator it = st.upper_bound({{l, INF}, 'z' + 1}), it2;
	it--;

	vector<pair<pair<int, int>, char>>	sec, gec;
	while (it != st.end()){
		int tl = (*it).first.first, tr = (*it).first.second;
		char c = (*it).second;
		if (tl >= r)	break;

		if (tl < l){
			sec.push_back({{tl, l}, c});
			sec.push_back({{l, min(r, tr)}, c});
			gec.push_back(*it);
		}
		if (tr > r){
			sec.push_back({{r, tr}, c});
			sec.push_back({{max(l, tl), r}, c});
			gec.push_back(*it);
		}
		it++;
	}	
	for (auto v:gec)
		st.erase(v);
	for (auto v:sec)
		st.insert(v);
	sec.clear();

	it = st.upper_bound({{l, INF}, 'z' + 1});
	it--;
	while (it != st.end()){
		int tl = (*it).first.first, tr = (*it).first.second;
		char c = (*it).second;
		if (tl >= r)	break;

		if (it != st.begin()){
			it2 = it;
			it2--;
			if ((*it2).first.second <= l)
				cnt[(*it2).second][c]--;
		}
		{
			it2 = it;
			it2++;
			if (it2 != st.end())
				cnt[c][(*it2).second]--;
		}	

		cnt[c][c] -= tr - tl - 1;
		sec.push_back(*it);
		it++;
	}	
	for (auto v:sec)
		st.erase(v);
	st.insert({{l, r}, ch});
	it = st.upper_bound({{l, INF}, 'z' + 1});
	it--;
	if (it != st.begin()){
		it2 = it;
		it2--;
		cnt[(*it2).second][ch]++;
	}	

	{
		it2 = it;
		it2++;
		if (it2 != st.end())
			cnt[ch][(*it2).second]++;
	}

	cnt[ch][ch] += r - l - 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> k;
	cin >> s;
	for (int i = 0; i < n;){
		int j = i + 1;
		while (j < n && s[j] == s[i])	j++;
		st.insert({{i, j}, s[i]});
		cnt[s[i]][s[i]] += j - i - 1;
		if (j != n)
			cnt[s[i]][s[j]]++;
		i = j;
	}

	while (q--){
		int type;	cin >> type;
		if (type == 2){
			string p;	cin >> p;
			int ret = 0;
			for (int i = 0; i < k; i++)
				for (int j = 0; j <= i; j++)
						ret += cnt[p[i]][p[j]];
			cout << ret + 1 << "\n";
		}
		else{
			int l, r;	cin >> l >> r;	l--;
			char ch;	cin >> ch;
			insert(l, r, ch);
		}
		/*for (int i = 0; i < k; i++){
			for (int j = 0; j < k; j++)
				cout << cnt['a' + i]['a' + j] << " ";
			cout << endl;
		}*/
	}
	return 0;
}