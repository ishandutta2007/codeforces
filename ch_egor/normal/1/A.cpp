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

	int64 n, m, a;

	scanf("%I64d %I64d %I64d", &n, &m, &a);

	printf("%I64d", ((n + a - 1) / a)*((m + a - 1) / a)); 

	fclose(stdin);
	fclose(stdout);

	return 0;
}