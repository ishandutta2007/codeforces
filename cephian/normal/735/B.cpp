#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 100005;
int n,x,y;
ll a[N];

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> x >> y;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);
	if(y < x) swap(x,y);
	double s1 = 0,s2=0;
	for(int i = 0; i < x; ++i) {
		s1 += a[n-1-i];
	}
	for(int i = 0; i < y; ++i) {
		s2 += a[n-x-1-i];
	}
	cout << setprecision(12) << fixed << s1/x + s2/y << "\n";

	return 0;
}