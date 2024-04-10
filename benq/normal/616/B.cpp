#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int main() {
	int n,m, maxx = 0;
	cin >> n >> m;
	F0R(i,n) {
		int minx = MOD;
		F0R(j,m) {
			int a;
			cin >> a;
			if (a<minx) minx = a;
		}
		if (minx > maxx) maxx = minx;
	}
	cout << maxx;
	return 0;
}