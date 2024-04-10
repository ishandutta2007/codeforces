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

int main() {
	ios::sync_with_stdio(0); cin.tie();
	ll n;
	cin >> n;
	if(n==1) cout << "-1\n";
	else cout << n << " " << n+1 << " " << n*(n+1) << "\n";
	return 0;
}