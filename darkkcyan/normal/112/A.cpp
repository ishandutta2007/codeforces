#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ve vector
#define ii pair<int, int>
#define ll pair<long, long>
#define sz(v) ((int) (v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define xx first
#define yy second
#define pb push_back

int main() {
	string a, b;
	cin >> ws >> a >> ws >> b;
	transform(all(a), a.begin(), ::tolower);
	transform(all(b), b.begin(), ::tolower);
	
	cout << a.compare(b);
	
	return 0;
}