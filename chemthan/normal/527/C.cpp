//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
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

int w, h, n;
set<int> sh, sv;
multiset<int> mth, mtv;

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>w>>h>>n;
	sh.insert(0); sh.insert(h); sv.insert(0); sv.insert(w); mth.insert(h); mtv.insert(w);
	FOR(i, n) {
		char s; int k; cin>>s>>k;
		if (s == 'H') {
			set<int>::iterator it = sh.lower_bound(k);
			set<int>::iterator it2 = it; it2--;
			sh.insert(k);
			mth.erase(mth.find(*it - *it2));
			mth.insert(k - *it2);
			mth.insert(*it - k);
		} else {
			
			set<int>::iterator it = sv.lower_bound(k);
			set<int>::iterator it2 = it; it2--;
			sv.insert(k);
			mtv.erase(mtv.find(*it - *it2));
			mtv.insert(k - *it2);
			mtv.insert(*it - k);
		}
		cout<<1LL * (*mth.rbegin()) * (*mtv.rbegin())<<"\n";
	}
}

int main() {
	solve();
	return 0;
}