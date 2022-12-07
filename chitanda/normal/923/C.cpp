#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

const int maxn = 300100;
int n, tot, rt;
int a[maxn], p[maxn];
int son[maxn * 30][2];
int cnt[maxn * 30];

void insert(int &t, int v, int dp){
	if(!t) t = ++tot;
	++cnt[t];
	if(dp == -1) return;
	bool k = v >> dp & 1;
	insert(son[t][k], v, dp - 1);
}

void find(int t, int v, int dp, int ans){
	--cnt[t];
	if(dp == -1){
		printf("%d ", ans);
		return;
	}
	bool k = v >> dp & 1;
	if(cnt[son[t][k]]) find(son[t][k], v, dp - 1, ans);
	else find(son[t][k ^ 1], v, dp - 1, ans | 1 << dp);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i){
		scanf("%d", p + i);
		insert(rt, p[i], 29);
	}
	for(int i = 1; i <= n; ++i)
		find(rt, a[i], 29, 0);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}