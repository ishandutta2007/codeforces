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

	string st;
	int n;

	cin >> st;
	n = st.size();

	bool good1 = false;
	bool good2 = false;

	for (int i = 0; i < n - 1; ++i)
	{
		if (good1 && st.substr(i, 2) == "BA")
		{
			good2 = true;
		}
		if (!good1 && st.substr(i, 2) == "AB")
		{
			good1 = true;
			++i;
		}
	}

	bool good3 = false;
	bool good4 = false;

	for (int i = 0; i < n - 1; ++i)
	{
		if (good3 && st.substr(i, 2) == "AB")
		{
			good4 = true;
		}
		if (!good3 && st.substr(i, 2) == "BA")
		{
			good3 = true;
			++i;
		}
	}

	if ((good1 && good2) || (good3 && good4))
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