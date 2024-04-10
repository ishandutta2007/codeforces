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

int n,a,b;
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n >> a >> b >> s;
	cout << (s[a-1]!=s[b-1]) << "\n";
	return 0;
}