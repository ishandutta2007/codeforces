#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e6 + 10;

int n, h[MAXN], st[MAXN], tl[MAXN], tr[MAXN], sec[MAXN];
map<int, int>	mp;

bool cmp(int u, int v){return h[u] > h[v];}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &h[i]);
	int mx = *max_element(h, h + n), cnt = 0;
	for (int i = 0; i < n; i++)	if (mx == h[i])	cnt++;
	copy(h, h + n, h + n);
	int t = 0;
	ll ans = 1ll*cnt*(cnt-1)/2;
	for (int i = 0; i < n<<1; i++){
		while (t && h[st[t - 1]] <= h[i])	t--;
		if (i>=n){
			if (h[i] < mx)
				tl[i - n] = (st[t - 1]>=n?st[t - 1] - n:st[t - 1]);
		}
		st[t++] = i;
	}
	
	reverse(h, h + (n<<1));
	t = 0;
	for (int i = 0; i < n<<1; i++){
		while (t && h[st[t - 1]] <= h[i])	t--;
		if (i>=n)
			if (h[i] < mx)
				tr[(n<<1)-i-1] = (n<<1)-1-(st[t - 1]>=n?st[t - 1]:st[t - 1]+n);
		st[t++] = i;
	}
	reverse(h, h + n);

	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = cnt; i < n;){
		int j = i;
		while (j < n && h[sec[i]] == h[sec[j]])	j++;
		mp.clear();
		for (; i < j; i++)	mp[tl[sec[i]]]++, ans += 2 - (tl[sec[i]] == tr[sec[i]]);
		for (auto x:mp)
			ans += 1ll * x.S * (x.S - 1) >> 1;
	}

	printf("%lld\n", ans);
	return 0;
}