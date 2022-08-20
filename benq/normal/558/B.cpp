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

int n, minlen = 999999,x,y, maxtimes = 0, counts[1000001][3];

int main() {
	cin >> n;
	FOR(i,1,n+1) {
		int a;
		cin >> a;
		counts[a][0]++;
		if (counts[a][1] == 0) counts[a][1] = i;
		counts[a][2] = i;
	}
	
	FOR(i,1,1000001) {
		if (counts[i][0]>maxtimes) {
			minlen = counts[i][2]-counts[i][1];
			x = counts[i][1];
			y = counts[i][2];
			maxtimes = counts[i][0];
		} else if (counts[i][0] == maxtimes && (counts[i][2]-counts[i][1])<minlen) {
			minlen = counts[i][2]-counts[i][1];
			x = counts[i][1];
			y = counts[i][2];
		}
	}
	
	cout << x << " " << y;
	return 0;
}