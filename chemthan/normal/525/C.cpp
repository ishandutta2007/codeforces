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
int s[1000001];
int t[1000001];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(s, 0); ms(t, 0);
	cin>>n;
	while (n--) {int l; cin>>l; s[l]++; t[l]++;}
	priority_queue<int> pq;
	FORd2(i, 1000001, 1) {
		if ((s[i] & 1) > 0 && t[i] > 0) {
			s[i]--; s[i - 1]++;
		}
		s[i] = (s[i] / 2) * 2;
		FOR(j, s[i]) pq.push(i);
	}
	ll ans = 0;
	while (pq.size() > 3) {
		int m = pq.top(); pq.pop(); pq.pop();
		int n = pq.top(); pq.pop(); pq.pop();
		ans += 1LL * m * n;
	}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}