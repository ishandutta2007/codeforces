#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
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



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,z,a=0;
	cin >> n >> m >> z;
	for(int i = 1; i <= z; ++i)
		a += i%n==0 && i%m==0;
	cout << a << "\n";
	return 0;
}