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

int n, k;
int s[2];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(s, 0);
	cin>>n>>k;
	FOR(i, n) {int a; cin>>a; s[a % 2]++;}
	k = n - k;
	if (s[0] == 0) {if ((n - k) % 2 == 0) cout<<"Daenerys"; else cout<<"Stannis"; return;}
	if (s[1] == 0) {cout<<"Daenerys"; return;}
	if (k == 0) {if (s[1] % 2 == 0) cout<<"Daenerys"; else cout<<"Stannis"; return;}
	if (k & 1) {
		if (k / 2 >= s[1]) {cout<<"Daenerys"; return;}
		if ((n - k) % 2 == 0 && k / 2 >= s[0]) {cout<<"Daenerys"; return;}
		cout<<"Stannis";
	}
	else {
		if (k / 2 >= s[0] && (n - k) % 2 == 1) {cout<<"Stannis"; return;}
		cout<<"Daenerys";
	}
}

int main() {
	solve();
	return 0;
}