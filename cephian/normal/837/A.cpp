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



int main() {
	fio;
	int m = 0;
	cin >> m;
	m = 0;
	while(!cin.eof()) {
		string s;
		cin >> s;
		int a = 0;
		for(char c : s) {
			if('A' <= c && c <= 'Z') ++a;
		}
		m = max(a,m);
	}
	cout << m << "\n";
}