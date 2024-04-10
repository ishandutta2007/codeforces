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

const string arr1[] = { "zero",
						"one",
						"two",
						"three",
						"four",
						"five",
						"six",
						"seven",
						"eight",
						"nine",
						"ten",
						"eleven",
						"twelve",
						"thirteen",
						"fourteen",
						"fifteen",
						"sixteen",
						"seventeen",
						"eighteen",
						"nineteen" 
};
const string arr2[] = { "twenty",
						"thirty",
						"forty",
						"fifty",
						"sixty",
						"seventy",
						"eighty",
						"ninety" 
};

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int s;

	scanf("%d", &s);

	if (s < 20)
	{
		cout << arr1[s];
	}
	else if (s % 10 == 0)
	{
		cout << arr2[s / 10 - 2];
	}
	else
	{
		cout << arr2[s / 10 - 2] << "-" << arr1[s % 10];
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}