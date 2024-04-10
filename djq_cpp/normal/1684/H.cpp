#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

char S[1000005];
int n, mxd[1000005], mnd[1000005];
bitset<256> msk[1000005]; 
void solve()
{
	scanf("%s", S);
	n = strlen(S);
	
	mnd[0] = mxd[0] = 0; msk[0] = 1;
	rep(i, n) {
		mxd[i + 1] = 0; msk[i + 1] = 0;
		mnd[i + 1] = mnd[i] + (S[i] - '0');
		int cs = 0;
		for(int j = 0; j <= min(3, i); j ++) {
			cs += (S[i - j] - '0') << j;
			mxd[i + 1] = max(mxd[i + 1], mxd[i - j] + cs);
		}
		cs = 0;
		for(int j = 0; j <= min(3, i); j ++) {
			cs += (S[i - j] - '0') << j;
			msk[i + 1] |= msk[i - j] << (mxd[i + 1] - mxd[i - j] - cs);
		}
	}
	
	int val = mnd[n];
	while((val & (val - 1)) || !msk[n][min(mxd[n] - val, 255)]) val ++;
	if(val == 0) {
		printf("-1\n"); return;
	}
	vector<PII> ans;
	for(int i = n - 1; i >= 0; ) {
		int cs = 0;
		for(int j = 0; j <= min(3, i); j ++) {
			cs += (S[i - j] - '0') << j;
			if(val - cs >= mnd[i - j] && val - cs <= mxd[i - j] && msk[i - j][min(mxd[i - j] - val + cs, 255)]) {
				ans.push_back(MP(i - j + 1, i + 1));
				i -= j + 1; val -= cs;
				break;
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i = (int)ans.size() - 1; i >= 0; i --) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}