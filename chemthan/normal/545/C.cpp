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
int x[100000];
int h[100000];
int res[100000][3];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(res, 0);
	cin>>n; FOR(i, n) {cin>>x[i]; cin>>h[i];}
	FORd2(i, n, 1) {
		res[i][0] = res[i + 1][0];
		if (x[i] - h[i] > x[i - 1]) res[i][0] = MAX(res[i][0], 1 + res[i + 1][1]);
		if (i == n - 1 || x[i] + h[i] < x[i + 1]) res[i][0] = MAX(res[i][0], 1 + res[i + 1][2]);
		res[i][1] = res[i + 1][0];
		if (x[i] - h[i] > x[i - 1]) res[i][1] = MAX(res[i][1], 1 + res[i + 1][1]);
		if (i == n - 1 || x[i] + h[i] < x[i + 1]) res[i][1] = MAX(res[i][1], 1 + res[i + 1][2]);
		res[i][2] = res[i + 1][0];
		if (x[i] - h[i] > x[i - 1] + h[i - 1]) res[i][2] = MAX(res[i][2], 1 + res[i + 1][1]);
		if (i == n - 1 || x[i] + h[i] < x[i + 1]) res[i][2] = MAX(res[i][2], 1 + res[i + 1][2]);
	}
	cout<<MAX(MAX(res[1][0], res[1][1] + 1), res[1][2] + 1);
}

int main()
{
	solve();
	return 0;
}