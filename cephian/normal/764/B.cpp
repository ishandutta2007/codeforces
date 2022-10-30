#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
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

int a[200005],n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i < n-i+1; ++i)
		if(i&1) swap(a[i],a[n-i+1]);
	for(int i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}