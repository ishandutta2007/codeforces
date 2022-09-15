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

int k;

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>k;
	if (k % 2 == 0) {cout<<"NO"; return;}
	if (k == 1) {cout<<"YES\n2 1\n1 2"; return;}
	int m = k * (k + 2);
	cout<<"YES\n"<<2 * k + 4<<" "<<m<<"\n"<<1<<" "<<2<<"\n";
	FOR(i, k - 1) cout<<1<<" "<<i + 3<<"\n"<<2<<" "<<k + i + 4<<"\n";
	FOR2(i, 3, k + 4) FOR2(j, i + 1, k + 4) if (i > k || j > k + 1 || (j - i != (k - 1) / 2)) cout<<i<<" "<<j<<"\n"<<k + i + 1<<" "<<k + j + 1<<"\n";
}

int main() {
	solve();
	return 0;
}