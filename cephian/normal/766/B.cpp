#include <algorithm>
#include <iostream>
#include <iomanip>
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

int a[100005],n;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);
	for(int i = 2; i < n; ++i) {
		if(a[i-2]+a[i-1] > a[i]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}