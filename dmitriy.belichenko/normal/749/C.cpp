
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
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
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
int n;
string s;
int r = 0;
int d = 0;
int cntr = 0;
int cntd = 0;
void checkR(int i)
{
	if (s[i] == 'R')
	{
		if (r == 0)
		{
			V++;
			SV = SV + 2;
			SV = SV - 3;

		}
		else SV = SV - 1;
	}
}
void checkD(int i)
{
	if (s[i] == 'D')
	{
		if (r == 0)
		{
			V++;
			SV = SV + 2;
			SV = SV - 3;

		}
		else SV = SV - 1;
	}
}
bool used[105];
vector<int> ans;
int cnt;
int main()
{
		 cin >> n >> s;
		 ios_base::sync_with_stdio(false), cin.tie(nullptr);
		 for (int i = 0; i < n; i++)
		 {
			 if (s[i] == 'D') cntd++;
			 if (s[i] == 'R') cntr++;
		 }
		 checkD(0);
		 checkR(0);
		 while (cntr> 0 && cntd > 0)
		 {
		   string t = "";
			 int p = s.length();
			 for (int i = 0; i <= p - 1 && cntr > 0 && cntd > 0; i++)
			 {
				
				 if (s[i] == 'D')
				 {
					 if (d == 0)
					 {
						 r++;
						 
						 t += 'D';
						 cntr--;
					 }
					 else d--;
				 }
				
				 if (s[i] != 'D') 
				 {
					 if (r == 0) 
					 {
						 d++;
						 
					     t += 'R';
						 cntd--;
					 }
					 else r--;
				 }
			 }
			 s = t;
			 SV++;
		 }
		 if (cntd == 0) cout << "R";
		 else cout << "D";
}