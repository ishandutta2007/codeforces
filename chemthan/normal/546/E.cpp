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

#define UNVISITED 0
#define VISITED 1

int n, m;
int s, t, mf, f;
int p[500];
int res[500][500];

void augment(int v, int minedge) {
	if (v == s) {f = minedge; return;}
	else if (p[v] > -1) {augment(p[v], min(minedge, res[p[v]][v])); res[p[v]][v] -= f; res[v][p[v]] += f;}
}

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m;
	ms(res, 0); int sum1 = 0, sum2 = 0; s = 2 * n, t = 2 * n + 1;
	int buf; FOR(i, n) {cin>>buf; res[s][i] = buf; sum1 += buf;} FOR(i, n) {cin>>buf; res[i + n][t] = buf; sum2 += buf;}
	if (sum1 != sum2) {cout<<"NO"; return;}
	FOR(i, n) {res[i][i + n] = INT_MAX;}
	while (m--) {
		int p, q; cin>>p>>q; p--; q--;
		res[p][q + n] = res[q][p + n] = INT_MAX;
	}
	mf = 0;
	while (1) {
		f = 0;
		vi vis(2 * n + 2, UNVISITED); vis[s] = VISITED; ms(p, -1);
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop(); if (u == t) break;
			FOR(i, 2 * n + 2) {if (res[u][i] > 0 && vis[i] == 0) {vis[i] = VISITED; p[i] = u; q.push(i);}}
		}
		augment(t, INT_MAX);
		if (f == 0) break;
		mf += f;
	}
	if (mf != sum1) {cout<<"NO"; return;}
	cout<<"YES\n"; FOR(i, n) {FOR(j, n) cout<<res[j + n][i]<<" "; cout<<"\n";}
}

int main(){
	solve();
	return 0;
}