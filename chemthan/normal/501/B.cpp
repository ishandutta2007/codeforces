#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 1010;
int n;
string s[maxn];
string t[maxn];
map<string, bool> st;
map<string, string> mp1;
map<string, bool> mp2;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {
		cin>>s[i]>>t[i];
		mp1[s[i]] = t[i];
		st[s[i]] = 1;
		mp2[t[i]] = 1;
	}
	int cnt = 0;
	FOR(i, 0, n) if (!mp2[s[i]]) cnt++;
	cout<<cnt<<endl;
	FOR(i, 0, n) {
		if (!mp2[s[i]]) {
			cout<<s[i]<<" ";
			string temp = s[i];
			while (st[temp]) temp = mp1[temp];
			cout<<temp<<endl;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}