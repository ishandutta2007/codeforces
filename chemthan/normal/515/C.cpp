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
char s[16];
int fp[10];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(fp, 0);
	cin>>n>>s;
	FOR(i, n) {
		switch (s[i]) {
		case '7':
		case '5':
		case '3':
		case '2':
			fp[s[i] - 48]++; break;
		case '9':
			fp[7]++; fp[3] += 2; fp[2]++; break;
		case '8':
			fp[7]++; fp[2] += 3; break;
		case '6':
			fp[5]++; fp[3]++; break;
		case '4':
			fp[3]++; fp[2] += 2; break;
		}
	}
	FORd(i, 10) {while (fp[i]--) cout<<i;}
}

int main() {
	solve();
	return 0;
}