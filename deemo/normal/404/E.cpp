//Such a trashy world!

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e6 + 10;

int n, ss[MAXN], tt[MAXN];
string s;
pair<int, int>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	if (s.back() == 'L')
		for (int i = 0; i < n; i++){
			if (s[i] == 'L')	s[i] = 'R';
			else	s[i] = 'L';
		}
	int cur = 0, mn = 0, mx = 0, tmx = 0;
	ss[0] = tt[0] = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == 'R')	cur++;
		else	cur--;
		mn = min(mn, cur);
		ss[i + 1] = cur;
		tt[i + 1] = ss[i + 1] + max(0, -mn);
		vec[i] = {mn, i + 1};
		if (i < n - 1)	mx = max(mx, tt[i + 1]);
		if (i < n - 1)	tmx = max(tmx, ss[i + 1]);
	}
	
	if (tmx < cur){
		cout << "1\n";
		return 0;
	}

	if (mx >= tt[n]){
		cout << "0\n";
		return 0;
	}

	sort(vec, vec + n);
	int cn = 0;
	int cc = n - 1;	mx = 0;
	while (cc >= 0 && vec[cc].first >= 0)	mx = max(mx, ss[vec[cc--].second]);
	for (int i = -1; mx < ss[n] + (-mn + (i + 1)); i--){
		cn++;
		while (cc >= 0 && vec[cc].first == i){
			auto v = vec[cc--];
			int dif = tt[n] - tt[v.second];
			mx = max(mx, ss[v.second]);
		}
	}
	cout << cn << "\n";
	return	0;
}