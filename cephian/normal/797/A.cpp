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

vi v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i = 2; n != 1; ++i) {
		while(n%i == 0) {
			v.push_back(i);
			n/=i;
		}
	}
	if(v.size() < k) cout << "-1\n";
	else {
		while(k > 1) {
			--k;
			cout << v.back() << " ";
			v.pop_back();
		}
		int p = 1;
		for(auto a : v)
			p*=a;
		cout << p << "\n";
	}
	return 0;
}