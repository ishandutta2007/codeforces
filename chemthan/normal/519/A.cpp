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

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int whi = 0, bla = 0;
	FOR(i, 8) {
		char line[9]; cin>>line;
		FOR(j, 8) {
			switch (line[j]) {
			case 'Q':
				whi += 9; break;
			case 'R':
				whi += 5; break;
			case 'B':
			case 'N':
				whi += 3; break;
			case 'P':
				whi += 1; break;
			case 'q':
				bla += 9; break;
			case 'r':
				bla += 5; break;
			case 'b':
			case 'n':
				bla += 3; break;
			case 'p':
				bla += 1; break;
			}
		}
	}
	if (whi == bla) cout<<"Draw";
	else if (whi > bla) cout<<"White";
	else cout<<"Black";
}

int main() {
	solve();
	return 0;
}