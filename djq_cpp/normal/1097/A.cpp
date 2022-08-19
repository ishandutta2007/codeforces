#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

string S[6];

int main()
{
	rep(i, 6) cin >> S[i];
	rep1(i, 5) if(S[i][0] == S[0][0] || S[i][1] == S[0][1]) {
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}