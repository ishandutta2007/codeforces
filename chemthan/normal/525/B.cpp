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

char s[200001];
int m;
int t[200001];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(t, 0);
	cin>>s>>m;
	int len = strlen(s);
	while (m--) {int a; cin>>a; a--; t[a] = (t[a] + 1) % 2;}
	int k = 0;
	FOR(i, len / 2) {
		if (t[i] == 1) k = (k + 1) % 2;
		if (k == 1) {int buf = s[i]; s[i] = s[len - i - 1]; s[len - i - 1] = buf;}
	}
	cout<<s;
}

int main() {
	solve();
	return 0;
}