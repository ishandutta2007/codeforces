#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

bool vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

string s;

int main() {	
	fio;
	cin >> s;
	int streak = 0;
	int diff_streak = 0, last = -1;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] != last) ++diff_streak;
		else diff_streak = 1;
		last = s[i];
		if(!vowel(s[i])) ++streak;
		else streak = 0;
		if(streak >= 3 && (s[i] != s[i-1] || s[i] != s[i-2])) {
			streak = 1;
			diff_streak = 1;
			cout << " ";
		}
		cout << s[i];
	}
	cout << "\n";
}