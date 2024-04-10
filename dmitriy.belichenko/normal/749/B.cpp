
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
int main()
{

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int v1x = x1 - x2;
	int v2x = x3 - x2;
	int v1y = y1 - y2;
	int v2y = y3 - y2;
	
	
	 v1x = x2 - x1;
	 v2x = x3 - x1;
	 v1y = y2 - y1;
	 v2y = y3 - y1;
	// ans1 = v1x - v2x;
	// ans2 = v1y - v2y;
	
	v1x = x2 - x3;
	v2x = x1 - x3;
	v1y = y2 - y3;
	v2y = y1 - y3;
	//ans1 = v1x - v2x;
	//ans2 = v1y - v2y;
//	cout << 3 << endl;
	set<pair<int, int> > S;
	pair<int, int> ans1, ans2 , ans3;
	ans1.first = x1 + x2 - x3;
	ans1.second = y1 + y2 - y3;
	ans2.first = x1 + x3 - x2;
	ans2.second = y1 + y3 - y2;
	ans3.first = x3 + x2 - x1;
	ans3.second = y3 + y2 - y1;
	S.insert(ans1);
	S.insert(ans2);
	S.insert(ans3);
	cout << S.size() << endl;
	for (auto p : S)
	{
		cout << p.first << " " << p.second << endl;
	}
}