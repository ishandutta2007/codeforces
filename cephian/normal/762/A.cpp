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

vector<ll> s;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	ll n;
	int k;
	cin >> n >> k; --k;
	for(ll i = sqrt(n); i > 0; --i) {
		if(n%i == 0) {
			s.push_back(i);
			if(i != n/i)
				s.push_back(n/i);
		}
	}
	sort(s.begin(),s.end());
	if(k >= s.size())
		cout << "-1\n";
	else
		cout << s[k] << "\n";
	return 0;
}