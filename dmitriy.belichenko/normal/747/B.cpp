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
bool used[1005];
int vert(int a)
{
	return ((a*(a - 1)) / 2);
}

int main()
{
	int n;

	cin >> n;
	string s;
	cin >> s;
	if (n % 4 != 0)
	{
		cout << "===";
		return 0;
	}
	int k1=0, k2=0, k3=0, k4 =0, k5= 0, kmax = 1000;
	bool kk1 = 0, kk2 = 0, kk3 = 0, kk4 = 0 ;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A')k1++;
		if (s[i] == 'C')k2++;
		if (s[i] == 'G')k3++;
		if (s[i] == 'T')k4++;
		if (s[i] == '?')k5++;
		kmax = max(k1, k2);
		kmax = max(kmax, k3);
		kmax = max(kmax, k4);
	}
	if (kmax > n / 4)
	{
		cout << "===";
		return 0;
	}
	k1= n/4 - k1;
	k2 = n / 4 - k2;
	k3 = n / 4 - k3;
	k4 = n / 4 - k4;
	//cout << k1 << k2 << k3 << k4;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '?')
		{
			if (k1 != 0)
			{
				s[i] = 'A';
				k1--;
			}
			else 
				if (k2 != 0)
				{
					s[i] = 'C';
					k2--;
				}
				else
					if (k3 != 0)
					{
						s[i] = 'G';
						k3--;
					}
					else
						if (k4 != 0)
						{
							s[i] = 'T';
							k4--;
						}
					
		}
		
	}
	cout << s;
}