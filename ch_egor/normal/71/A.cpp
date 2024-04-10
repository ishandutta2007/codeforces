#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	string st;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> st;

		if (st.size() > 10)
		{
			cout << st[0] << st.size() - 2 << *(st.end() - 1) << "\n";
		}
		else
		{
			cout << st << "\n";
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}