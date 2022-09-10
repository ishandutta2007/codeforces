#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

#define ll unsigned long long
#define pll pair<ll,ll>
#define mod 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); --i)

#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-5

int main()
{
	int n;
	cin >> n;
	newVecRead(a, n);

	sortVec(a);
	cout << a[n / 2];
	return 0;
}