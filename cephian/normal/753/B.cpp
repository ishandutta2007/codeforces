#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

bool hx[10]={0};

int get1(const string& x,const string& s) {
	int ans = 0;
	for(int i = 0; i < 4; ++i)
		ans += x[i]==s[i];
	return ans;
}

int get2(const string& x,const string& s) {
	int ans = 0;
	for(int i = 0; i < 4; ++i)
		hx[x[i]]=1;
	for(int i = 0; i < 4; ++i)
		ans += hx[s[i]] && s[i]!=x[i];
	for(int i = 0; i < 4; ++i)
		hx[x[i]]=0;
	return ans;
}

void pr(pii p) {
	cout << "(" << p.first << "," << p.second << ")\n";
}

void cnv(string& s) {
	for(int i = 0; i < 4; ++i)
		s[i] -= '0';
}

vector<string> all;
vector<string> tmp;

void prune(const string& guess, int r1, int r2) {
	for(int i = 0; i < all.size(); ++i)
		if(get1(guess,all[i]) == r1 && get2(guess,all[i]) == r2)
			tmp.push_back(all[i]);
	swap(all,tmp);
	tmp.clear();
}

bool ct() {
	string s = "....";
	s[0] = 9;
	s[1] = 8;
	s[2] = 7;
	s[3] = 6;
	for(auto x : all)
		if(x==s) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	for(int i = 0; i <= 9999; ++i) {
		string s = "....";
		s[3] = i%10;
		s[2] = (i/10)%10;
		s[1] = (i/100)%10;
		s[0] = (i/1000)%10;
		if(s[0]==s[1]||s[0]==s[2]||s[0]==s[3]||s[1]==s[2]||s[1]==s[3]||s[2]==s[3]) continue;
		all.push_back(s);
	}
	int r1,r2;
	while(1) {
		for(int i = 0; i < 4; ++i)
			cout << char(all[0][i]+'0');
		cout << endl;
		cin >> r1 >> r2;
		if(r1 == 4) return 0;
		prune(all[0],r1,r2);
	}
	return 0;
}