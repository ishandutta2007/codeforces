#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

set<char> se;
string s;

bool ok(char c){
	return se.find(c) == se.end();
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	se.insert('a');
	se.insert('e');
	se.insert('i');
	se.insert('o');
	se.insert('u');
	cin >> s;
	cout << s[0];
	int cnt = 0;
	if (ok(s[0])) cnt = 1;
	for (int i = 1; i < s.size(); i++){
		if (ok(s[i])){
			cnt++;
			if (cnt > 2){
				if (s[i] != s[i - 1] || s[i] != s[i - 2]){
					cout << ' ' << s[i];
					cnt = 1;
				} else {
					cout << s[i];
					cnt++;
				}
			} else cout << s[i];
		} else {
			cout << s[i];
			cnt = 0;
		}
	}
}