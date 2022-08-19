#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

const int MAGIC = 250;
const int MAXA = 16384;

int datp[200005];
int* curd = datp;
int* stasp[200005];
int** curs = stasp;
int tagp[5005];
int* curt = tagp;

struct sqrt_dep
{
	int n, nt;
	int* dat;
	int** cnt;
	int* tag;
	int tot;
	
	void init(vector<int> from)
	{
		n = from.size();
		nt = n / MAGIC;
		
		dat = curd;
		cnt = curs;
		tag = curt;
		curd += n;
		curs += nt;
		curt += nt;
		
		rep(i, n) dat[i] = from[i];
		for(int i = 1; i < n; i ++) dat[i] ^= dat[i - 1];
		
		rep(i, nt) {
			cnt[i] = new int[MAXA];
			memset(cnt[i], 0, MAXA * sizeof(int));
			tag[i] = 0;
		}
		rep(i, nt) rep(j, MAGIC) cnt[i][dat[i * MAGIC + j]] ++;
		
		tot = n == 0 ? 0 : dat[n - 1];
	}
	
	void modify(int id, int val)
	{
		int gp = id / MAGIC;
		
		if(gp < nt)
		for(int i = id; i % MAGIC != 0 && i < n; i ++) {
			cnt[gp][dat[i]] --;
			dat[i] ^= val;
			cnt[gp][dat[i]] ++;
		}
		
		for(int i = (id + MAGIC - 1) / MAGIC; i < nt; i ++) tag[i] ^= val;
		for(int i = max(n - n % MAGIC, id); i < n; i ++) dat[i] ^= val;
		
		tot ^= val;
	}
	
	int query()
	{
		if(tot != 0) return -1;
		int ans = 0;
		rep(i, nt) ans += cnt[i][tag[i]];
		for(int i = n - n % MAGIC; i < n; i ++) ans += dat[i] == 0;
		return n - ans;
	}
}djp[200005];

int n, k, q;
int a[200005], b[200005];
int dif[200005];
int ans, totn, ca[200005];

vector<int> tot[200005];
void init()
{
	for(int i = 0; i <= n; i ++) tot[i % k].push_back(dif[i]);
	rep(i, k) djp[i].init(tot[i]);
	
	ans = totn = 0;
	rep(i, k) {
		ca[i] = djp[i].query();
		if(ca[i] == -1) totn ++;
		else ans += ca[i];
	}
}

void modify(int id, int val)
{
	dif[id] ^= val;
	
	if(ca[id % k] == -1) totn --;
	else ans -= ca[id % k];
	
	djp[id % k].modify(id / k, val);
	ca[id % k] = djp[id % k].query();
	
	if(ca[id % k] == -1) totn ++;
	else ans += ca[id % k];
}

int main()
{
	scanf("%d%d%d", &n, &k, &q);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	
	dif[0] = a[0] ^ b[0];
	for(int i = 1; i < n; i ++) dif[i] = a[i] ^ b[i] ^ a[i - 1] ^ b[i - 1];
	dif[n] = a[n - 1] ^ b[n - 1];
	
	init();
	printf("%d\n", totn > 0 ? -1 : ans);
	
	rep(i, q) {
		int id, val;
		char tp;
		scanf("\n%c%d%d", &tp, &id, &val);
		id --;
		int* cur = tp == 'a' ? a : b;
		modify(id, cur[id] ^ val);
		modify(id + 1, cur[id] ^ val);
		printf("%d\n", totn > 0 ? -1 : ans);
		cur[id] = val;
	}
	return 0;
}