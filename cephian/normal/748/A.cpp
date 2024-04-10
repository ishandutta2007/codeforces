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

int n,m,k;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> m >> k;
	cout << 1+((k-1)/2)/m << " " << 1+((k-1)/2)%m << ((k&1)?" L\n":" R\n");

	return 0;
}