#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n;
string s[MAXN];

bool check(string a, string b){
	int m = a.size();
	for (int i = 0; i + m <= b.size(); i++)
		if (b.substr(i, m) == a)
			return true;
	return false;
}

bool cmp(string a, string b){return a.size() < b.size();}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i + 1 < n; i++)
		if (!check(s[i], s[i+1])){
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
	return 0;
}