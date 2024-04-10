#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<list>
#define X first
#define Y second
#define INF 1987654321
#define PI 3.14159265358979323
#define MOD 10007
using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
int a[10];
int main() {
	for (int i = 0; i < 10; i++)
		a[i] = 2;
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		char c;
		int x;
		scanf("%c %d ", &c, &x);
		if (c == '|')
		{
			for (int j = 0; j < 10; j++)
				if (x&(1 << j))a[j] = 1;
		}
		if (c == '&')
		{
			for (int j = 0; j < 10; j++)
				if (!(x&(1 << j)))a[j] = 0;
		}
		if (c == '^')
		{
			for (int j = 0; j < 10; j++)
			{
				if (x&(1 << j))
				{
					if (a[j] > 1)a[j] = 5 - a[j];
					else a[j] = 1 - a[j];
				}
			}
		}
	}
	vector<char> ansc;
	vector<int> ansi;
	int temp = 0;
	for (int i = 9; i >= 0; i--)
		if (a[i] <= 1) temp += (1 << i);
	ansc.push_back('|');
	ansi.push_back(temp);
	temp = 0;
	for (int i = 9; i >= 0; i--)
		if (a[i] ==0 || a[i]==3) temp += (1 << i);
	ansc.push_back('^');
	ansi.push_back(temp);
	printf("%d\n", ansi.size());
	for (int i = 0; i < ansi.size(); i++)
		printf("%c %d\n", ansc[i], ansi[i]);
}