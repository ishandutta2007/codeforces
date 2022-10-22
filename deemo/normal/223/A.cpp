#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>

using namespace std;

const int max_n = 2e5 + 2;

string s;
vector<int>	vec, h;
vector<int>	sec[max_n];
vector<pair<int, int>>	st;
int n;
int par[max_n], nex[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	h.resize(n);
	sec[0].push_back(-1);
	for (int i = 0; i < n; i++){
		if (!vec.empty() && ((vec.back() == '(' && s[i] == ')') || (vec.back() == '[' && s[i] == ']')))
			vec.pop_back();
		else
			vec.push_back(s[i]);
		h[i] = vec.size();
		sec[h[i]].push_back(i);
	}	

	for (int i = 0; i < n; i++){
		if (i != 0)	par[i] = par[i - 1];
		if (s[i] == '[')	par[i]++;
	}

	nex[n - 1] = n;
	st.push_back({h[n - 1], n - 1});
	for (int i = n - 2; i >= 0; i--){
		while (!st.empty() && st.back().first >= h[i])
			st.pop_back();
		if (st.empty())
			nex[i] = n;
		else	
			nex[i] = st.back().second;
		st.push_back({h[i], i});
	}

	int maxi = 0, l = -1, r = -1;
	int t = 0, g = n;
	for (int i = 0; i < n; i++){
		int pos = lower_bound(sec[t].begin(), sec[t].end(), g) - sec[t].begin();
		pos--;
		int x = sec[t][pos];	
		if (x <= i){
			t = h[i];
			g = nex[i];
			continue;
		}
		int z;
		if (i == 0)
			z = par[x];
		else
			z = par[x] - par[i - 1];
		if (z > maxi){
			maxi = z;
			l = i;
			r = x;
		}	
		t = h[i];
		g = nex[i];
	}
	cout << maxi << endl;
	if (maxi != 0){
		for (int i = l; i <= r; i++)
			cout << s[i];
		cout << endl;
	}
	return 0;
}