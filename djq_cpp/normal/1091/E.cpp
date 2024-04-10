//not finished yet
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

struct segt
{
	LL dat[1048576], adv[1048576];
	
	void pushdown(int cur)
	{
		dat[cur << 1] += adv[cur];
		adv[cur << 1] += adv[cur];
		dat[cur << 1 | 1] += adv[cur];
		adv[cur << 1 | 1] += adv[cur];
		adv[cur] = 0;
	}
	
	void pushup(int cur)
	{
		dat[cur] = min(dat[cur << 1], dat[cur << 1 | 1]);
		adv[cur] = 0;
	}
	
	void add(int l, int r, LL val, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(l == cl && r == cr) {
			dat[cv] += val;
			adv[cv] += val;
			return;
		}
		pushdown(cv);
		int mid = cl + cr >> 1;
		if(r <= mid) add(l, r, val, cv << 1, cl, mid);
		else if(l > mid) add(l, r, val, cv << 1 | 1, mid + 1, cr);
		else {
			add(l, mid, val, cv << 1, cl, mid);
			add(mid + 1, r, val, cv << 1 | 1, mid + 1, cr);
		}
		pushup(cv);
	}
	
	LL query(int l, int r, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(l == cl && r == cr) return dat[cv];
		pushdown(cv);
		int mid = cl + cr >> 1;
		if(r <= mid) return query(l, r, cv << 1, cl, mid);
		else if(l > mid) return query(l, r, cv << 1 | 1, mid + 1, cr);
		else return min(query(l, mid, cv << 1, cl, mid), query(mid + 1, r, cv << 1 | 1, mid + 1, cr));
	}
}tre;

int n, deg[500005]; 
void add_v(int id)
{
	tre.add(id, n, -1);
	if(deg[id] < id) tre.add(deg[id], id - 1, 1);
	deg[id] ++;
}
void rem_v(int id)
{
	deg[id] --;
	tre.add(id, n, 1);
	if(deg[id] < id) tre.add(deg[id], id - 1, -1);
}
bool check()
{
	return tre.query(0, n) >= 0;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &deg[i]);
	sort(deg, deg + n);
	reverse(deg, deg + n);
	while(n > 0 && deg[n - 1] == 0) n --;
	rep(i, n) deg[n] ^= deg[i] & 1;
	
	int lsum = 0;
	int pos = n;
	LL sum = 0;
	for(int i = 0; i <= n; i ++) {
		while(pos > i && deg[pos] <= i) {
			sum += deg[pos];
			pos --;
		}
		while(pos < i) {
			pos ++;
			sum -= deg[pos];
		}
		sum -= deg[i];
		tre.add(i, i, sum + 1LL * (i + 1) * pos);
	}
	
	bool ok = false;
	int cpos = n;
	while(deg[cpos] <= n) {
		while(cpos > 0 && deg[cpos] > deg[cpos - 1]) {
			int cur = deg[cpos] - deg[cpos - 1];
			rep(i, cur) add_v(cpos - 1);
			rep(i, cur) rem_v(cpos);
			cpos --;
		}
		
		if(check()) {
			printf("%d ", deg[cpos]);
			ok = true;
		}
		rep(i, 2) add_v(cpos);
	}
	if(!ok) printf("-1\n");
	return 0;
}