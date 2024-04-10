#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int max_n = 1e5 + 100;
const int MOD = 1e9 + 7;

string s, pat;
int f[max_n], save[max_n], ans[max_n], p[max_n];

void fill(){
	int k = 0;
	for (int i = 1; i < pat.size(); i++){
		while (k && pat[i] != pat[k])	k = f[k];
		if (pat[i] == pat[k])	k++;
		f[i + 1] = k;
	}
	k = 0;
	for (int j = 0; j < s.size(); j++){
		while (k && pat[k] != s[j])	k = f[k];
		if (pat[k] == s[j])	k++;
		save[j] = k;	
		if (k == pat.size())	k = f[k];
	}
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> pat;
	fill();

	int ind = -1;
	for (int i = 0; i < s.size(); i++){
		ans[i + 1] = ans[i];

		if (save[i] == pat.size())	ind = i + 1 - pat.size();
		if (ind >= 0)	ans[i + 1] += p[ind] + ind + 1;
		ans[i + 1] %= MOD;

		p[i + 1] = (p[i] + ans[i + 1]) % MOD;
	}
	cout << ans[s.size()] << endl;
	return 0;
}