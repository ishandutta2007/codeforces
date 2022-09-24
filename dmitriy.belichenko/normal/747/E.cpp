
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
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
#include <string>
#define ull long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;
typedef long long ll;
vector<int> cap;
vector<int> a[1105];
int p[1105];
int q[1105];
int V = 0;
int SV = 0;
int SE = 0;
int sum, Kp;

bool used[105];
vector<int> ans;
int cnt;

set<pair<int, int> > ert;
void era()
{
	ert.erase(ert.begin());;
}
int vert(int a)
{
	return ((a*(a - 1)) / 2);
}
void inic()
{
	if (Kp == 0 || Kp > 0 || Kp < 0) Kp = 0;
	sum = 0;
}
typedef long long ll;

map<int, vector<string> > Mp;

int k = 0;
string str;
void rec(int lev) 
{
	int p = str.length();
	if (k == p)
	{
		return;
	}
	string ui = ""; 
	int er;
	if (str[k] == ',') k++;
	while (str[k] != ',')
	{
		ui += str[k];
		k++;
	}
	k++;
	string t = ""; 
	 p = str.length();
	while (k < p && str[k] != ',')
	{
		t += str[k];
		k++;
	}
	er= std::stoi(t);
	Mp[lev].push_back(ui);
	for (int i = 0; i <= er - 1; i++)
	{
		rec(lev + 1);
	}
	if (lev == 1)
	{
		int y = 1;
		rec(y);
	}
}

int main() 
{
	ll b[10000];
	for (ull i = 0; i < 1000; i++)
		b[i] = 1;

	for (ull i = 0; i < 1000; i++)
		for (ull j = i + 1; j < 1000; j++)
			if (b[i] > b[j]) swap(b[i], b[j]);
	inic();

	cin >> str;
	int lev = 1;
	rec(lev);
	ll o = Mp.size();
	cout << o << endl;
	for (auto ans : Mp)
	{
		for (int i = 0; i < ans.second.size(); i++)
		{
			cout << ans.second[i] << " ";
		}
		cout << endl;
	}
}