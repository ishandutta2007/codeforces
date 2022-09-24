#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define sz(a) ((int)(a).size())
typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;


const int N = 2e5 + 10;

vi v[N];
set<int> s[N];
int dead[N];
int deg[N];


int main()
{
	
	int n;
	cin >> n;
	if (n % 2) cout << "contest" << endl;
	else cout << "home" << endl;
	return 0;
}