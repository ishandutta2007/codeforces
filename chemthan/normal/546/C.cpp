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
ll gcd(ll a, ll b){ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int n;
queue<int> a, b;

void solve()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int k, m;
	cin>>n;
	cin>>k; while (k--) {cin>>m; a.push(m);}
	cin>>k; while (k--) {cin>>m; b.push(m);}
	ll ans = 0;
	while (1)
	{
		ans++;
		int x = a.front(); a.pop(); int y = b.front(); b.pop();
		if (x > y) {a.push(y); a.push(x);}
		else {b.push(x); b.push(y);}
		if (a.empty()) {cout<<ans<<" "<<2; return;}
		if (b.empty()) {cout<<ans<<" "<<1; return;}
		if (ans > 40000000) {cout<<-1; return;}
	}
}

int main()
{
	solve();
	return 0;
}