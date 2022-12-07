#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

bool check(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
	string s;
	cin >> s;
	int n = s.size();
	string cur; cur += s[0];
	for(int i = 1; i < n; ++i){
		if(cur.size() >= 2 && !check(s[i]) && !check(s[i - 1]) && !check(s[i - 2]) && (s[i] != s[i - 1] || s[i] != s[i - 2])){
			cout << cur << ' ';
			cur = "";
		}
		cur += s[i];
	}
	cout << cur;
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}