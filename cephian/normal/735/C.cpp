#include <algorithm>
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

ll F[300];

int main() {
	ios::sync_with_stdio(0); cin.tie();
	F[0] = 1;
	F[1] = 2;
	for(int i = 2; i < 300; ++i)
		F[i] = F[i-1] + F[i-2];
	ll n;
	cin >> n;
	for(int i = 0;;++i) {
		if(F[i] > n) {
			cout << i-1 << "\n";
			return 0;
		}
	}

	return 0;
}