#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

const LL INF = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(20210506);

struct tnode
{
	tnode* lson,* rson;
	int prior;
	LL suml, len, dif, tag;
	tnode(LL l = 0, LL d = 0)
	{
		lson = rson = NULL;
		prior = rng();
		suml = len = l; dif = d; tag = 0;
	}
};
void oper(tnode* cur, LL val)
{
	if(cur != NULL) {
		cur->dif += val; cur->tag += val;
	}
}
void pushdown(tnode* cur)
{
	oper(cur->lson, cur->tag);
	oper(cur->rson, cur->tag);
	cur->tag = 0;
}
LL getsl(tnode* cur)
{
	return cur == NULL ? 0 : cur->suml;
}
void pushup(tnode* cur)
{
	cur->suml = getsl(cur->lson) + getsl(cur->rson) + cur->len;
}

void merge(tnode*& ret, tnode* u, tnode* v)
{
	if(u == NULL) ret = v;
	else if(v == NULL) ret = u;
	else {
		if(u->prior > v->prior) {
			pushdown(u); ret = u;
			merge(ret->rson, u->rson, v);
		} else {
			pushdown(v); ret = v;
			merge(ret->lson, u, v->lson);
		}
		pushup(ret);
	}
}
void splitd(tnode*& u, tnode*& v, tnode* ori)
{
	if(ori == NULL) u = v = NULL;
	else {
		pushdown(ori);
		if(ori->dif > 0) {
			v = ori;
			splitd(u, v->lson, ori->lson);
			pushup(v);
		} else {
			u = ori;
			splitd(u->rson, v, ori->rson);
			pushup(u);
		}
	}
}
void splitp(tnode*& u, tnode*& v, tnode* ori, LL cx)
{
	if(ori == NULL) u = v = NULL;
	else {
		pushdown(ori);
		if(cx <= getsl(ori->lson)) {
			v = ori;
			splitp(u, v->lson, ori->lson, cx);
			pushup(v);
		} else if(cx >= getsl(ori->lson) + ori->len) {
			u = ori;
			splitp(u->rson, v, ori->rson, cx - getsl(ori->lson) - ori->len);
			pushup(u);
		} else {
			LL lu = cx - getsl(ori->lson), ru = ori->len - lu;
			merge(u, ori->lson, new tnode(lu, ori->dif));
			merge(v, new tnode(ru, ori->dif), ori->rson);
			delete ori;
		}
	}
}

LL lx, ly;
tnode* rt;
void clear_t(LL X)
{
	lx = X; ly = 0; rt = NULL;
}
void move_r(LL D)
{
	lx += D;
}
void conv_r(LL D)
{
	tnode* u,* v;
	splitd(u, v, rt);
	merge(u, u, new tnode(D));
	merge(rt, u, v);
}
void add_t(LL dat)
{
	if(lx >= 0) {
		ly += lx * dat; oper(rt, dat);
	} else {
		ly -= lx * dat;
		tnode* u,* v;
		splitp(u, v, rt, -lx);
		oper(u, -dat); oper(v, dat);
		merge(rt, u, v);
	}
}

LL dfs(tnode* cur)
{
	if(cur == NULL) return 0;
	pushdown(cur);
	LL ret = dfs(cur->lson) + dfs(cur->rson) + cur->len * cur->dif;
	delete cur;
	return ret;
}
LL query_t(LL x)
{
	tnode* u,* v;
	splitp(u, v, rt, x - lx);
	LL ret = ly + dfs(u); dfs(v);
	return ret;
}

int n;
LL a[35005], l[35005], r[35005];

LL solve(LL X)
{
	clear_t(X);
	rep(i, n) {
		move_r(l[i] - a[i]);
		conv_r(r[i] - l[i]);
		add_t(1);
	}
	return query_t(X);
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%lld%lld%lld", &a[i], &l[i], &r[i]);
	
	LL sum = 0;
	rep(i, n) sum += a[i];
	LL L = -sum, R = sum;
	while(L < R) {
		LL mid = (L + R) >> 1;
		if(solve(mid) > solve(mid + 1)) L = mid + 1;
		else R = mid;
	}
	
	printf("%lld\n", solve(R));
	return 0;
}