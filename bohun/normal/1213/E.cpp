#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
#define bignum tuple <ll, ll, ll>
 
 
using namespace std;
int n;
string s;
int t[2][2];
map <pair<int, int>, bool> jest;

bool good(int x, int y, int z) {
	if(jest[mp(x, y)] == 1)
		return 0;
	if(jest[mp(y, z)] == 1)
		return 0;
	if(n > 1 && jest[mp(z, x)] == 1)
		return 0;
	return 1;
}

int w[3];

int main() {
	cout << "YES\n";
	cin >> n;
	FOR(i, 0, 1) {
		cin >> s;
		t[i][0] = s[0] - 'a';
		t[i][1] = s[1] - 'a';
		jest[mp(t[i][0], t[i][1])] = 1;
	}
	
	if(t[0][0] == t[1][0] && t[0][0] != t[0][1] && t[1][0] != t[1][1]) {
		w[t[0][0]] = 1;
		int A = -1;
		int B = -1;
		FOR(i, 0, 2)
			if(w[i] == 0) {
				w[i] = 1;
				A = i;
				break;
			}
		FOR(i, 0, 2)
			if(w[i] == 0) {
				w[i] = 1;
				B = i;
				break;
			}	
		
		FOR(i, 1, n)
			cout << (char) ('a' + A);
		FOR(i, 1, n)
			cout << (char) ('a' + B);
		FOR(i, 1, n)
			cout << (char) ('a' + t[0][0]);
		return 0;
	}
	
	
	if(t[0][1] == t[1][1] && t[0][0] != t[0][1] && t[1][0] != t[1][1]) {
		w[t[0][1]] = 1;
		int A = -1;
		int B = -1;
		FOR(i, 0, 2)
			if(w[i] == 0) {
				w[i] = 1;
				A = i;
				break;
			}
		FOR(i, 0, 2)
			if(w[i] == 0) {
				w[i] = 1;
				B = i;
				break;
			}	
		
		FOR(i, 1, n)
			cout << (char) ('a' + t[0][1]);
		FOR(i, 1, n)
			cout << (char) ('a' + B);
		FOR(i, 1, n)
			cout << (char) ('a' + A);
		return 0;
	}
	
	if(t[0][0] == t[1][1] && t[1][0] == t[0][1] && t[0][0] != t[0][1]) {
		w[t[0][1]] = 1;
		w[t[0][0]] = 1;
		int B = -1;
		FOR(i, 0, 2)
			if(w[i] == 0) {
				w[i] = 1;
				B = i;
				break;
			}
		
		FOR(i, 1, n)
			cout << (char) ('a' + t[0][1]);
		FOR(i, 1, n)
			cout << (char) ('a' + B);
		FOR(i, 1, n)
			cout << (char) ('a' + t[0][0]);
		return 0;
	}
	
	
	int a = t[0][0];
	int b = t[0][1];
	if(b == a) {
		if(a == 0)
			b = 1;
		else
			b = 0;
	}
	int c = -1;
	FOR(i, 0, 2) 
		if(i != a && i != b) {
			c = i;
			break;
		}
	
	
	if(good(b, a, c)) {
		w[0] = b;
		w[1] = a;
		w[2] = c;
		FOR(i, 0, 3 * n - 1) 
			cout << (char) ('a' + w[i % 3]);		
	}
	else if(good(b, c, a)) {
		w[0] = b;
		w[1] = c;
		w[2] = a;
		FOR(i, 0, 3 * n - 1) 
			cout << (char) ('a' + w[i % 3]);
	}
		
	
	
	
	
	return 0;
}