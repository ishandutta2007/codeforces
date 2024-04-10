#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> v;

int gcd(int a, int b) {
	return (b==0)?a:gcd(b,a%b);
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(!v.empty() && gcd(*v.rbegin(),a) != 1) {
			int k = *v.rbegin();
			int b = 2;
			while(gcd(k,b) != 1 || gcd(b,a) != 1)
				++b;
			v.push_back(b);
		}
		v.push_back(a);
	}
	cout << v.size()-n << "\n";
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << "\n";
	return 0;
}