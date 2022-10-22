#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

const int max_n = 1e5 + 200;

string s;
int q;
int save[max_n][200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> q;
	
	save[0][s[0]] = 1;
	for (int i = 1; i < s.size(); i++){
		for (char c = 'x'; c <= 'z'; c++)
			save[i][c] = save[i - 1][c];
		save[i][s[i]]++;
	}	

	vector<int>	sec;
	while(q--){
		sec.clear();
		int l, r;	cin >> l >> r;	l--, r--;
		if (r - l + 1 < 3){
			cout << "YES" << endl;
			continue;
		}
		for (char c = 'x'; c <= 'z'; c++){
			if (l == 0)	sec.push_back(save[r][c]);
			else	sec.push_back(save[r][c] - save[l - 1][c]);
		}
		sort(sec.begin(), sec.end());
		int cnt = 0;
		bool fl = 0;
		for (int i = 0; i < 2; i++){
			if (sec[i] != sec[i + 1])	cnt++;
			if (sec[i + 1] - sec[i] > 1)	fl = 1;
		}
		if (fl || cnt > 1)
			cout << "NO" << endl;
		else 
			cout << "YES" << endl;
	}
	return 0;
}