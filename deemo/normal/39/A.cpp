#include<bits/stdc++.h>

using namespace std;

int a, ans = 0;
string s;
vector<pair<int, int>>	vec, sec;

bool cmp1(pair<int, int> f, pair<int, int> g){
	if (f.first != g.first)
		return f.first < g.first;
	return f.second < g.second;
}	

bool cmp2(pair<int, int> f, pair<int, int> g){
	if (f.first != g.first)
		return f.first > g.first;
	return f.second > g.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a;
	cin >> s;

	for (int i = 0; i < s.size();){
		int mul = 1;
		if (s[i] == '-')	mul = -1;
		if (i)	i++;

		int c = 0;
		char temp = s[i];
		while (i < s.size() && '0' <= s[i] && s[i] <= '9')
			c = c * 10 + int(s[i] - '0'), i++;
		if (temp != '0')
			c = max(c, 1);
		
		if (s[i] == '*')	i++;
		
		bool fl = 0;
		if (s[i] == 'a')	fl = 1;
		i += 3;

		if (mul == -1)
			sec.push_back({c, fl});
		else
			vec.push_back({c, fl});
	}

	sort(vec.begin(), vec.end(), cmp1);
	sort(sec.begin(), sec.end(), cmp2);

	for (auto v:sec){
		if (v.second){
			ans -= v.first * a++;
		}
		else{
			ans -= v.first * ++a;
		}
	}

	for (auto v:vec)
		if (v.second)
			ans += v.first * a++;
		else
			ans += v.first * ++a;

	cout << ans << "\n";
	return 0;
}