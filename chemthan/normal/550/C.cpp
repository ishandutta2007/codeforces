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

char n[101];
bool list[1000];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(list, 0); ms(n, 0);
	FOR2(i, 0, 1000) if (i % 8 == 0) list[i] = 1;
	cin>>n;
	int len = strlen(n);
	FOR(i, len) if (list[(n[i] - 48)]) {cout<<"YES\n"<<n[i]; return;}
	FOR(i, len) FOR2(j, i + 1, len) if (list[(n[i] - 48) * 10 + (n[j] - 48)]) {cout<<"YES\n"<<n[i]<<n[j]; return;}
	FOR(i, len) FOR2(j, i + 1, len) FOR2(k, j + 1, len) if (list[(n[i] - 48) * 100 + (n[j] - 48) * 10 + (n[k] - 48)]) {cout<<"YES\n"<<n[i]<<n[j]<<n[k]; return;}
	cout<<"NO";
}

int main() {
	solve();
	return 0;
}