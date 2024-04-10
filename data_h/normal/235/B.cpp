#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <vector>

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;

#define PB push_back
#define MP make_pair
#define foreach(e,x) for(typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e);

const int MAX_N = 100000 + 10;
int N;
double p[MAX_N], w[MAX_N];
double c[MAX_N], d[MAX_N];

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; ++ i)
		scanf("%lf", &p[i]);
	
	for(int i = N; i >= 1; -- i) {
		d[i] = d[i + 1] * p[i] + p[i] * 2 * i * (1 - p[i + 1]);
		c[i] = c[i + 1] * p[i] + p[i] * (1 - p[i + 1]);
	}
	
	double ret = 0;
	for(int i = N; i >= 1; -- i) {
		w[i] = p[i] * (w[i + 1] + d[i + 1] - c[i + 1] * 2 * i + c[i + 1]) + p[i] * (1 - p[i + 1]);
		//printf("%.10f\n", w[i]);
		ret += (1 - p[i - 1]) * w[i];
	}
	printf("%.10f\n", ret);
	//system("pause");
}

int main()
{
	solve();
	return 0;
}