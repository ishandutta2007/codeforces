#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <memory.h>
#include <numeric>
#include <utility>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <cstring>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>

#define forit(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define clr(q) while (!q.empty()) q.pop()
#define alc(a, v) memset(a, v, sizeof(a))

#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef pair<int, int> pii;
typedef vector<int> vi;
int N;

char str[105];
main() {
	scanf("%d", &N);
	scanf("%s", str);
	int i;
	int sum = 1, rlt = 0;
	for (i = 0; i < N; i ++) {
		if (sum) rlt ++;
		sum += str[i] - '0';
		
 		sum /= 2;
	}
	cout << rlt << endl;
}