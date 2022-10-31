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


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll a[2],i;
	cin >> a[1] >> a[0];
	for(i = 1; ; ++i) {
		if(a[i&1] < i)
			break;
		a[i&1] -= i;
	}
	cout << ((i&1)?"Vladik\n":"Valera\n");

	return 0;
}