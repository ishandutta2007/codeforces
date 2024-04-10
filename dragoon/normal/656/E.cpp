#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

int n;
int w[12][12];

int input(int i, int j) {
	j == n ? input(i + 1, 0) :
		i != n ? scanf("%d", &w[i][j]), input(i, j + 1) : 0;
	return 0;
}

int floyd(int k, int i, int j) {
	j == n ? floyd(k, i + 1, 0) :
		i == n ? floyd(k + 1, 0, 0) :
			k != n ? w[i][j] = min(w[i][j], w[i][k] + w[k][j]), floyd(k, i, j + 1) : 0;
	return 0;
}

int ans = 0;
int findAns(int i, int j) {
	j == n ? findAns(i + 1, 0) :
		i != n ? ans = max(ans, w[i][j]), findAns(i, j + 1) : 0;
	return 0;
}

int main()
{
	scanf("%d", &n);
	input(0, 0);
	floyd(0, 0, 0);
	findAns(0, 0);
	printf("%d\n", ans);
	return 0;
}