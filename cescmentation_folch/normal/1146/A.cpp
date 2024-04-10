#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin >> a;
	int n = a.size();
	int s = 0;
	for (auto d : a) if (d == 'a') ++s;
	cout << min(n, 2*s-1) << '\n';
}