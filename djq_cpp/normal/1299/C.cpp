#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[1000005];
vector<pair<LL, int> > hv;

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	
	rep(i, n) {
		LL csum = a[i];
		int ccnt = 1;
		while(!hv.empty() && hv.back().first * ccnt >= csum * hv.back().second) {
			csum += hv.back().first;
			ccnt += hv.back().second;
			hv.pop_back();
		}
		hv.push_back(MP(csum, ccnt));
	}
	rep(i, hv.size()) rep(j, hv[i].second) printf("%.10lf\n", 1.0 * hv[i].first / hv[i].second);
	return 0;
}