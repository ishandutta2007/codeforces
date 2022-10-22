#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<numeric>
#include<cstring>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 10;
const int MAXK = 26 + 2;

int n, m, k, lst[MAXK], sec[MAXK];
char ch[MAXN];
string s;
ll ans = 1, d[MAXK];

bool cmp(int u, int v){return lst[u] < lst[v];}

int main(){
	scanf("%d %d", &n, &k);
	scanf("%s", ch);	s = ch;	m = s.size();
	
	memset(lst, -1, sizeof(lst));
	for (int i = 0; i < m; i++){
		int t = 1;
		for (int j = 0; j < k; j++)	t = (t + d[j]) % MOD;
		ans = (ans + MOD - d[s[i] - 'a']) % MOD;
		ans = (ans + t) % MOD;
		d[s[i] - 'a'] = t;
		lst[s[i] - 'a'] = i;
	}
	iota(sec, sec + k, 0);
	sort(sec, sec + k, cmp);

	int cur = 0;
	for (int i = 0; i < n; i++, cur = (cur + 1) % k){
		int t = 1;
		int c = sec[cur];
		for (int j = 0; j < k; j++)	t = (t + d[j]) % MOD;
		ans = (ans + MOD - d[c]) % MOD;
		ans = (ans + t) % MOD;
		d[c] = t;
	}

	printf("%d\n", (int)ans);
	return	0;
}