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
	int n,t;
	cin >> n >> t;
	int m = 240-t;
	int a = 0;
	while(m >= 5*(a+1)) {
		++a;
		m-=5*a;
	}
	cout << min(a,n) << "\n";
	return 0;
}