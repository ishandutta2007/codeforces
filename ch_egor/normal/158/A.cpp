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

	int n, k;
	int arr[55];

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	int count = 1;

	while ((count < n) && (arr[count] == arr[count - 1] || count < k) && arr[count] != 0)
	{
		++count;
	}

	printf("%d", ((arr[0]!=0) ?count:0));

	fclose(stdin);
	fclose(stdout);

	return 0;
}