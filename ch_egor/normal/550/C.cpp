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

const int MA = 124;

string arr[124] = {
	"8",
	"16",
	"24",
	"32",
	"40",
	"48",
	"56",
	"64",
	"72",
	"80",
	"88",
	"96",
	"104",
	"112",
	"120",
	"128",
	"136",
	"144",
	"152",
	"160",
	"168",
	"176",
	"184",
	"192",
	"200",
	"208",
	"216",
	"224",
	"232",
	"240",
	"248",
	"256",
	"264",
	"272",
	"280",
	"288",
	"296",
	"304",
	"312",
	"320",
	"328",
	"336",
	"344",
	"352",
	"360",
	"368",
	"376",
	"384",
	"392",
	"400",
	"408",
	"416",
	"424",
	"432",
	"440",
	"448",
	"456",
	"464",
	"472",
	"480",
	"488",
	"496",
	"504",
	"512",
	"520",
	"528",
	"536",
	"544",
	"552",
	"560",
	"568",
	"576",
	"584",
	"592",
	"600",
	"608",
	"616",
	"624",
	"632",
	"640",
	"648",
	"656",
	"664",
	"672",
	"680",
	"688",
	"696",
	"704",
	"712",
	"720",
	"728",
	"736",
	"744",
	"752",
	"760",
	"768",
	"776",
	"784",
	"792",
	"800",
	"808",
	"816",
	"824",
	"832",
	"840",
	"848",
	"856",
	"864",
	"872",
	"880",
	"888",
	"896",
	"904",
	"912",
	"920",
	"928",
	"936",
	"944",
	"952",
	"960",
	"968",
	"976",
	"984",
	"992"
};


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string st;
	int n;

	cin >> st;
	n = st.size();

	bool good = false;

	for (int i = 0; i < n; ++i)
	{
		if (st[i] == '0')
		{
			good = true;
		}
	}

	if (good)
	{
		printf("YES\n");
		printf("0");

		fclose(stdin);
		fclose(stdout);

		return 0;
	}
	else
	{
		string now;
		int poz = 0;

		for (int i = 0; i < MA; ++i)
		{
			now = arr[i];
			poz = 0;

			for (int j = 0; j < n; ++j)
			{
				if (poz < now.size() && now[poz] == st[j])
				{
					++poz;
				}
			}

			if (poz >= now.size())
			{
				printf("YES\n");
				cout << now;

				fclose(stdin);
				fclose(stdout);

				return 0;
			}
		}

		printf("NO");
	}


	fclose(stdin);
	fclose(stdout);

	return 0;
}