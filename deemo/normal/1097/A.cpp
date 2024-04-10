#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int cnt[2000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < 5; i++){
		string t; cin >> t;
		cnt[t[0]]++;
		cnt[t[1]]++;
	}
	if (cnt[s[0]] || cnt[s[1]])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}