/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int main()
{
	int n;
	cin >> n;
	cout << n/2 << endl;

	if (n%2 == 0)
	{
		for (int i = 0; i < n/2; ++i)
			cout << 2 << ' ';
	}

	else
	{
		cout << 3 << ' ';

		for (int i = 0; i < n/2 - 1; ++i)
			cout << 2 << ' ';
	}


}