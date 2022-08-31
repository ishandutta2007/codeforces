#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;

int a[N];
set <int> s;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		s.insert(a[i]);
	}

	if (s.size() > 3)
	{
		cout << "NO";
		return 0;
	}

	if (s.size() <= 2)
	{
		cout << "YES";
		return 0;
	}

	set <int>::iterator i = s.begin();
	int x = *i;
	++i;
	int y = *i;
	++i;
	int z = *i;

	if (y-x == z-y)
		cout << "YES";

	else
		cout << "NO";
}