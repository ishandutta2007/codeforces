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

int n;
int k1, k2;
queue<int> arr1;
queue<int> arr2;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%d", &k1);
	
	int x;
	for (int i = 0; i < k1; ++i)
	{
		scanf("%d", &x);
		arr1.push(x);
	}

	scanf("%d", &k2);
	for (int i = 0; i < k2; ++i)
	{
		scanf("%d", &x);
		arr2.push(x);
	}

	bool good = false;
	for (int i = 0; i < 50000000; ++i)
	{
		if (arr1.empty())
		{
			cout << i << " " << 2;
			good = true;
			break;
		}
		else if (arr2.empty())
		{
			cout << i << " " << 1;
			good = true;
			break;
		}
		else
		{
			k1 = arr1.front();
			k2 = arr2.front();

			if (k1 > k2)
			{
				arr1.push(k2);
				arr1.push(k1);
			}
			else
			{
				arr2.push(k1);
				arr2.push(k2);
			}

			arr1.pop();
			arr2.pop();
		}
	}

	if (!good)
	{
		cout << -1;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}