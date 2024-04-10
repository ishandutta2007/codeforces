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

int n;
char s[200001];
char t[200001];
int p[70000];
int q[256];
int r[256];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(p, -1); ms(q, -1); ms(r, -1);
	cin>>n>>s>>t;
	queue<ii> ans; int dis = 0;
	FOR(i, n) if (s[i] != t[i]) dis++;
	FOR(i, n) {
		if (s[i] != t[i]) {
			int j = p[(s[i]<<8) + t[i]];
			if (j > -1) {cout<<dis - 2<<"\n"<<i + 1<<" "<<j + 1; return;}
			p[(t[i]<<8) + s[i]] = i;
			if (ans.empty()) {j = q[s[i]]; if (j > -1) ans.push(ii(i, j));}
			if (ans.empty()) {j = r[t[i]]; if (j > -1) ans.push(ii(i, j));}
			q[t[i]] = r[s[i]] = i;
		}
	}
	if (!ans.empty()) {cout<<dis - 1<<"\n"<<ans.front().first + 1<<" "<<ans.front().second + 1; return;}
	cout<<dis<<"\n"<<-1<<" "<<-1;
}

int main() {
	solve();
	return 0;
}