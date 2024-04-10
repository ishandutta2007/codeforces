#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;


typedef long long int int64;


const int N = (int) 1e5 + 1;
int a[N];
int st[N];
int sz = 0;
int o2[N];

int main(int, char **)
{


	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	memset(st, -1, sizeof st);
	for (int i = 0; i < n; i++)
		if (i == a[i])
		{
			o2[sz] = i;
			st[i] = sz++;
		}
	for (int i = 0; i < n; i++)
		if (st[a[i]] == -1)
		{
			cout <<-1;
			return 0;
		}
	cout << sz << endl;
	for (int i = 0; i < n; i++)
	cout << st[a[i]] + 1 << " ";
	cout << endl;
	for (int i = 0; i < sz; i++)
		cout << o2[i] + 1 << " " ;
	cout << endl;




	return 0;
}