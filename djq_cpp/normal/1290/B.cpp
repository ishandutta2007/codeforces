#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, q;
char ch[200005];
int cnt[26][200005];

int main()
{
	scanf("%s", ch);
	n = strlen(ch);
	rep(i, n) rep(j, 26) cnt[j][i + 1] = cnt[j][i] + (ch[i] == j + 'a');
	
	scanf("%d", &q);
	rep(i, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		l --; r --;
		int tot = 0;
		rep(j, 26) if(cnt[j][r + 1] != cnt[j][l]) tot ++;
		if(r - l > 0 && tot <= 2 && ch[l] == ch[r]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}