#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 100228

int n;
bool been[SIZE];
int dir[SIZE];
int d[SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	char h;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (h == '>')
			dir[i] = 1;
		else
			dir[i] = -1;
	}
	for (int i = 0; i < n; i++)
		cin >> d[i];
	int nx = 0;
	while (true)
	{
		if (nx < 0 || nx >= n)
		{
			cout << "FINITE" << endl;
			return 0;
		}
		if (been[nx])
		{
			cout << "INFINITE" << endl;
			return 0;
		}
		been[nx] = true;
		nx += d[nx] * dir[nx];
	}
	return 0;
}