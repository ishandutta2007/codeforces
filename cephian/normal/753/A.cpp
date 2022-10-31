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

int n;
vector<int> a;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		a.push_back(i);
		n-=i;
	}
	a[a.size()-1] += n;
	cout << a.size() << "\n";
	for(int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	cout << "\n";

	return 0;
}