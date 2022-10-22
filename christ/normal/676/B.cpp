#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
double arr[21][21]; int n,t;
bool full[21][21]; int cnt = 0;
const double EPS = 1e-6;
void go (int i, int j, double am) {
	if (i > n) return;
	if (full[i][j]) go(i+1,j+1,am/2), go(i+1,j-1,am/2);
	else {
		double add = min(1-arr[i][j],am);
		arr[i][j] += add;
		double left = am - add;
		go(i+1,j+1,left/2); go(i+1,j-1,left/2);
		if (arr[i][j] >= (1-EPS)) full[i][j] = 1, cnt++;
	}
}
int main() {
	scanf ("%d %d",&n,&t);
	for (int i = 1; i <= t; i++) go(1,10,1);
	printf ("%d\n",cnt);
    return 0;
}