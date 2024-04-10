//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
#define FORd2(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

char s[100001];
vector<int> ab, ba;

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>s; int len = strlen(s);
	FOR(i, len - 1) {
		if (s[i] == 'A' && s[i + 1] == 'B') ab.push_back(i);
		else if (s[i] == 'B' && s[i + 1] == 'A') ba.push_back(i);
		if (sz(ab) + sz(ba) > 3 && sz(ab) > 0 && sz(ba) > 0) {cout<<"YES"; return;}
	}
	FOR(i, sz(ab)) FOR(j, sz(ba)) if (abs(ab[i] - ba[j]) > 1) {cout<<"YES"; return;}
	cout<<"NO";
}

int main() {
	solve();
	return 0;
}