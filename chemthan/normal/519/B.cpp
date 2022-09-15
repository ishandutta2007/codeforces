//#include <bits/stdc++.h>
#include <iostream>
#include <map>
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
int a[100000], b[100000];
map<int, int> s, t;

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n;
	FOR(i, n) {cin>>a[i]; s[a[i]]++;}
	FOR(i, n - 1) {cin>>b[i]; s[b[i]]--; t[b[i]]++;}
	FOR(i, n) {if (s[a[i]]) {cout<<a[i]<<"\n"; break;}}
	FOR(i, n - 2) {int c; cin>>c; t[c]--;}
	FOR(i, n - 1) {if (t[b[i]]) {cout<<b[i]; break;}}
}

int main() {
	solve();
	return 0;
}