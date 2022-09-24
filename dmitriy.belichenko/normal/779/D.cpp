#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ull unsigned long long
#define ll long long
#define ld long double
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
ull INF = 1e9 + 7;

using namespace std;

int n, k;

long long res = 0;

bool comp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first - a.second < b.first - b.second) return true;
    else return false;
}

string t, p;
const int N = 2e5 + 10;
int a[N];

bool check(int cur)
{
    string s = t;
    for (int i = 0; i < cur; i++)
    {
        
        s[a[i]] = '0';
    }
    int pp = 0;
    int i=0;
    while (pp < p.length() && i < t.length())
    {
        if (s[i] == p[pp]) pp++;
        i++;
    }
    if (pp == p.length()) return 0;
     return 1;
}

int main()
{
    cin >> t >> p;
    for (int i = 0; i < t.length(); i++)
    {
        cin >> a[i];
        a[i] --;
    }
int m = 0; 
int l = 0;
int r = t.size();
    while (l < r)
	{
		m = (l + r + 1) / 2;
		if (check(m)) r = m - 1;
		else l = m;
	}
	cout << l;
}