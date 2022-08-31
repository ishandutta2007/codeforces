/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int main()
{
	int n;
	cin >> n;
	set <string> s;
	for (int i = 0; i < n; ++i) 
	{
		string t;
		cin >> t;
		if (s.find(t) != s.end())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
			s.insert(t);
		}
	}
}