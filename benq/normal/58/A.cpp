#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

string s;

int find(int index, char x) {
	while (index<s.length()) {
		if (s[index] == x) return index+1;
		index ++;
	}
	return index+1;
}

int main() {
	cin >> s;
	if (find(find(find(find(find(0,'h'),'e'),'l'),'l'),'o') <= s.length()) cout << "YES";
	else cout << "NO";
	return 0;
}