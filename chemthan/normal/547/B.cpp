//#include <bits/stdc++.h>
#include <iostream>
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
int a[200000];
int ri[200000];
int le[200000];
int ans[200000];

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n;
	FOR(i, n) cin>>a[i];
	for(int i = n - 1; i >= 0; i--) {if (i == n - 1) {ri[i] = i; continue;} int j = i + 1; while (1) {if (a[i] > a[j]) {ri[i] = j - 1; break;} if (j == n - 1) {ri[i] = j; break;} if (j == ri[j]) j++; else j = ri[j];}}
	FOR(i, n) {if (i == 0) {le[i] = i; continue;} int j = i - 1; while (1) {if (a[i] > a[j]) {le[i] = j + 1; break;} if (j == 0) {le[i] = j; break;} if (j == le[j]) j--; else j = le[j];}}
	ms(ans, 0);
	FOR(i, n) {ans[ri[i] - le[i]] = MAX(ans[ri[i] - le[i]], a[i]);}
	FORd(i, n - 1) ans[i] = MAX(ans[i], ans[i + 1]);
	FOR(i, n) cout<<ans[i]<<" ";
}

int main(){
	solve();
	return 0;
}