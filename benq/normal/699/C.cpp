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
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define INF 9999;

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, a[105], rest[100][3];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) cin >> a[i];
	rest[1][0] = 1;
	if (a[1] & 1) rest[1][1] = 0;
	else rest[1][1] = INF;
	if (a[1] & 2) rest[1][2] = 0;
	else rest[1][2] = INF;
	FOR(i,2,n+1) {
        rest[i][0] = min(min(rest[i-1][0],rest[i-1][1]),rest[i-1][2])+1;
        if (a[i] & 1) rest[i][1] = min(rest[i-1][0],rest[i-1][2]);
        else rest[i][1] = INF;
        if (a[i] & 2) rest[i][2] = min(rest[i-1][0],rest[i-1][1]);
        else rest[i][2] = INF;
	}
	cout << min(min(rest[n][0],rest[n][1]),rest[n][2]);
}