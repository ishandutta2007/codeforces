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

int N = 20000;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	int n;
	cin >> n;
	int y = N;
	for(int i = 0; i < n; ++i) {
		int a;
		string type;
		cin >> a >> type;
		if(type == "North")
			y += a;
		else if(type == "South")
			y -= a;
		if(y < 0 || y > N || ((y==0||y==N)&&(type=="East"||type=="West"))) {
			cout << "NO\n";
			return 0;
		}
		// cout << i << " : " << y << endl;
	}
	if(y==N) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}