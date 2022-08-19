#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
string S[8];
int sta[8][5][5], cnt;
int mat[125][125], ans[125][125], tmp[125][125];

void mul(int A[][125], int B[][125])
{
	rep(i, cnt) rep(j, cnt) tmp[i][j] = 0;
	rep(i, cnt) rep(j, cnt) rep(k, cnt)
	tmp[i][k] = (tmp[i][k] + 1LL * A[i][j] * B[j][k]) % MOD;
	rep(i, cnt) rep(j, cnt) A[i][j] = tmp[i][j];
}

int main()
{
	cin >> n >> m;
	rep(i, n) cin >> S[i];
	
	rep(i, n) rep(j, S[i].size()) rep(k, j + 1) sta[i][j][k] = cnt ++;
	
	rep(i, n) rep(j, S[i].size()) rep(k, j + 1) {
		int bs = sta[i][j][k];
		if(j + 1 == (int)S[i].size()) {
			rep(l, n) if(k < (int)S[l].size()) {
				bool ok = true;
				rep(t, k + 1) if(ok && S[l][t] != S[i][t + j - k]) ok = false;
				if(!ok) continue;
				if(k + 1 == (int)S[l].size()) rep(m, n) mat[bs][sta[m][0][0]] ++;
				else mat[bs][sta[l][k + 1][0]] ++;
			}
		} else {
			mat[bs][sta[i][j + 1][k + 1]] ++;
			rep(l, n) if(k + 1 == (int)S[l].size()) {
				bool ok = true;
				rep(t, k + 1) if(ok && S[l][t] != S[i][t + j - k]) ok = false;
				if(!ok) continue;
				mat[bs][sta[i][j + 1][0]] ++;
			}
		}
	}
	
	rep(i, cnt) ans[i][i] = 1;
	for(int i = 30; i >= 0; i --) {
		mul(ans, ans);
		if(m >> i & 1) mul(ans, mat);
	}
	
	int ret = 0;
	rep(i, n) ret = (ret + ans[sta[i][0][0]][0]) % MOD;
	printf("%d\n", ret);
	return 0;
}