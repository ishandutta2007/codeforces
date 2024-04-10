#pragma "fastmath"
#pragma "sse4"
#pragma "ofast"
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <valarray>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ld __float128
#define mt make_tuple
#define fst first
using namespace std;
int main()
{
	int n , m ;
	int s = 0, mx = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
	{
	    int x;
	    cin >> x;
	    s += x;
	    mx = max(x , mx);
	}
	cout << max( mx , ( s + m - 1) / n + 1) << " "<< mx + m;
}