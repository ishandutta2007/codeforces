#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int main() {
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << ((a+b+c)*(a+b+c)-a*a-c*c-e*e);
	return 0;
}