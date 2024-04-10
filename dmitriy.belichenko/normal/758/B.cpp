
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
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
long long b[100005];
using namespace std;


int main() 
{
	
//	freopen("parenthr.in", "r", stdin);
//	freopen("parenthr.out", "w", stdout);

		string s , t;
		cin >> s;
		int n = s.length();
		map <char, int> m;
		t.resize(n);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != '!' && s[i] != '!')
			{
				t[i] = s[i];
				for (int j = i; j >= 0; j = j - 4)
				{
					int k = s[i];
					t[j] = k;
					s[i] = k;
				}
				for (int j = i; j < n; j =j + 4)
				{
					int k = s[i];
					t[j] = k;
					s[i] = k;
				}
			}
		}
		
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '!' && s[i] != 'R') m[t[i]]++;
		}
		int a = m['R'];
		int b = m['B'];
		int c = m['Y'];
		int d = m['G'];
		cout << a << " " << b << " " << c << " " << d << endl;

		return 0;
	}