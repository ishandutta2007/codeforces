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
	int n, m, k;
	cin >> n >> m >> k;

	int lane = (k-1)/(2*m) + 1;
	char side = (k%2)?'L':'R';
	int desk = (((k-1)%(2*m))/2)+1;

	cout << lane << ' ' << desk << ' ' << side << endl;
}