#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<set>

using namespace std;

set<string> st;
map<string, int>	cnt, cnt2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int mx1 = 0, mx2 = 0;
	vector<string>	vec;

	while (cin >> s){
		vec.clear();
		string t = "";
		t += s[0];
		t += s[2];

		for (int i = 3; i < (int)s.size();){
			int j = i;
			while (j < (int)s.size() && s[j] != '\\')	t += s[j++];
			cnt2[t]++;
			i = j + 1;

			if (i < (int)s.size()){
				t += s[j];
				vec.push_back(t);
			}

		}

		int c = 0;
		for (int i = (int)vec.size() - 1; i >= 0; i--){
			cnt[vec[i]] += c;
			if (st.count(vec[i]) == 0)	c++;
			st.insert(vec[i]);
		}
	}

	for (auto ss:cnt)
		mx1 = max(mx1, ss.second);
	for (auto ss:cnt2)
		mx2 = max(mx2, ss.second);
	cout << mx1 << " " << mx2 << "\n";
	return	0;
}