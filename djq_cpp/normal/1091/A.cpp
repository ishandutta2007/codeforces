#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int main()
{
	int y, b, r;
	cin >> y >> b >> r;
	cout << min(y + 2, min(b + 1, r)) * 3 - 3;
	return 0;
}