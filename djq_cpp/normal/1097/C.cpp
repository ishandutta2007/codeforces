#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int check0(string S)
{
	int tot = 0;
	rep(i, S.length()) {
		tot += S[i] == '(' ? 1 : -1;
		if(tot < 0) return -1; 
	}
	return tot;
}

int check1(string S)
{
	int tot = 0;
	for(int i = S.length() - 1; i >= 0; i --) {
		tot += S[i] == ')' ? 1 : -1;
		if(tot < 0) return -1; 
	}
	return tot;
}

int n;
string S[100005];
int tot0[500005], tot1[500005], toto;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, n) cin >> S[i];
	rep(i, n) {
		int a0 = check0(S[i]), a1 = check1(S[i]);
		if(a0 == 0 && a1 == 0) toto ++;
		else if(a0 != -1) tot0[a0] ++;
		else if(a1 != -1) tot1[a1] ++;
	}
	int ans = toto / 2;
	rep1(i, 500000) ans += min(tot0[i], tot1[i]);
	cout << ans << endl; 
	return 0;
}