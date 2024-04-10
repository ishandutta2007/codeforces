#include <bits/stdc++.h>
using namespace std;
 
const int Block = 450;
 
char s[200010];
int len;
char t[200010];
int m;
 
struct Tire{
	int son[200010][26];
	int cnt[200010];
	int tot;
	int newnode(){
		memset(son[tot], -1, sizeof(son[tot]));
		cnt[tot] = 0, tot++;
		return tot - 1;
	}
	void init(){tot = 0, newnode();}
	void insert(char *s, int len){
		int now = 0;
		for (int i = 0; i < len; i++){
			if (son[now][s[i] - 'a'] == -1) son[now][s[i] - 'a'] = newnode();
			now = son[now][s[i] - 'a'];
		}
		cnt[now]++;
	}
}T;
 
long long cnt1[200010], cnt2[200010];
int fail[1000010];
 
void Buildfail(char *s, int m){
	int j = -1;
	fail[0] = -1;
	for (int i = 1; i <= m; i++){
		while (j >= 0 && s[j] != s[i - 1]) j = fail[j];
		fail[i] = ++j;
		if (i != m && s[i] == s[fail[i]] && fail[fail[i]] != -1) fail[i] = fail[fail[i]];
	}
}
 
void solve(){
	t[m] = '\0';
	Buildfail(t, m);
	for (int i = 0, k = 0; i < len; i++){
		while (k >= 0 && t[k] != s[i]) k = fail[k];
		k++;
		if (k == m) cnt2[i]++, cnt1[i - m + 1]++;
	}
}
 
int main(){
	scanf("%s", s), len = strlen(s);
	int n; scanf("%d", &n);
	T.init();
	for (int i = 0; i < n; i++){
		scanf("%s", t), m = strlen(t);
		if (m <= Block) T.insert(t, m);
		else solve();
	}
	for (int i = 0; i < len; i++){
		int now = 0, j = i;
		while (now != -1){
			cnt1[i] += T.cnt[now], cnt2[j - 1] += T.cnt[now];
			if (j == len) break;
			now = T.son[now][s[j] - 'a'], j++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < len; i++){
		ans += 1ll * cnt2[i] * cnt1[i + 1];
	}
	printf("%I64d\n", ans);
	return 0;
}