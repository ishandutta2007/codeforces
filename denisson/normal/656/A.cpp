#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const bool is_testing = 0;
//const int p = 997;
const int MOD = (int)1e9;
const int MOD2 = (int)1e9 + 11;
const int MAXN = (int)2e5 + 7;

int n;

int main()
{
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //freopen("love.in", "r", stdin);
    //freopen("love.out", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
	cin >> n;
	if (n <= 12)
		cout << pow(2, n);
	else
	{
		ll k = 8092;
		n -= 13;
		forn(asfaf, n)
			k *= 2;
		cout << k;
	}
    //system("pause");          
    return 0;
}