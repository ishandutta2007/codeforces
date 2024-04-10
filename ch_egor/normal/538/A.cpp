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

using namespace std;

typedef long long int int64;
typedef long double double80;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string st;
	string need = "CODEFORCES";
	string now;
	bool good = false;

	cin >> st;

	for (int i = 0; i < st.size(); ++i)
	{
		for (int j = i; j <= st.size(); ++j)
		{
			now = st.substr(0, i) + st.substr(j, st.size());

			if (now == need)
			{
				good = true;
			}
		}
	}

	if (good)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}