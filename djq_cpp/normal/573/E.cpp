#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int seed = 200206;
int rng()
{
	return seed = 79851780LL * seed % MOD;
}
struct tnode
{
	int pr, siz;
	LL tag, dat;
	tnode* lson,* rson;
	tnode(LL val = 0)
	{
		pr = rng(); siz = 1; tag = 0; dat = val;
		lson = rson = NULL;
	}
};
void oper(tnode* cur, LL val)
{
	if(cur == NULL) return;
	cur->tag += val;
	cur->dat += val;
}
int gsiz(tnode* cur)
{
	return cur == NULL ? 0 : cur->siz;
}
void pushdown(tnode* cur)
{
	oper(cur->lson, cur->tag);
	oper(cur->rson, cur->tag);
	cur->tag = 0;
}
void pushup(tnode* cur)
{
	cur->siz = gsiz(cur->lson) + gsiz(cur->rson) + 1;
}

LL split(tnode*& ru, tnode*& rv, tnode* cur, LL k0, LL k1)
{
	LL ret = k0;
	if(cur == NULL) ru = rv = NULL;
	else {
		pushdown(cur);
		if(cur->dat < k0 + k1 * (gsiz(cur->lson) + 1)) {
			rv = cur;
			ret = split(ru, rv->lson, cur->lson, k0, k1);
			pushup(rv);
		} else {
			ru = cur;
			ret = split(ru->rson, rv, cur->rson, k0 + k1 * (gsiz(cur->lson) + 1), k1);
			pushup(ru);
		}
	}
	return ret;
}
void merge(tnode*& ret, tnode* u, tnode* v)
{
	if(u == NULL) ret = v;
	else if(v == NULL) ret = u;
	else {
		if(u->pr > v->pr) {
			pushdown(u);
			ret = u;
			merge(ret->rson, u->rson, v);
		} else {
			pushdown(v);
			ret = v;
			merge(ret->lson, u, v->lson);
		}
		pushup(ret);
	}
}

int n, a[1000005];
tnode* rt;

LL dfs(tnode* v)
{
	if(v == NULL) return 0;
	pushdown(v);
	LL ret = dfs(v->lson) + dfs(v->rson) + max(v->dat, 0LL);
	return ret;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) {
		tnode* u,* v,* w;
		w = new tnode(split(u, v, rt, 0, a[i]));
		merge(v, w, v);
		oper(v, a[i]);
		merge(rt, u, v);
	}
	
	printf("%lld\n", dfs(rt));
	return 0;
}