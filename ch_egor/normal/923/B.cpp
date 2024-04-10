#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

struct node
{
	ll x;
	int y;
	ll mod;
	node *l;
	node *r;
	int sz;
	ll sum;
};

node *new_node(ll x)
{
	node *ans = new node();

	ans->x = x;
	ans->sum = x;
	ans->sz = 1;
	ans->y = rand() ^ (rand() << 15);
	ans->mod = 0;
	ans->l = nullptr;
	ans->r = nullptr;

	return ans;
}

ll get_sum(node *t)
{
	if (t == nullptr) return 0ll;
	return t->sum;
}

int get_sz(node *t)
{
	if (t == nullptr) return 0;
	return t->sz;
}

ll get_x(node *t)
{
	if (t == nullptr) return -1;
	return t->x;
}

void add(node *t, ll x)
{
	if (t == nullptr) return;
	t->mod += x;
	t->x += x;
	t->sum += x * t->sz;
}

void push(node *t)
{
	if (t == nullptr) return;
	add(t->l, t->mod);
	add(t->r, t->mod);
	t->mod = 0;
}

void calc(node *t)
{
	t->sz = 1 + get_sz(t->l) + get_sz(t->r);
	t->sum = t->x + get_sum(t->l) + get_sum(t->r);
}

node *merge(node *t1, node *t2)
{
	if (t1 == nullptr) return t2;
	if (t2 == nullptr) return t1;
	
	push(t1);
	push(t2);

	if (t1->y > t2->y)
	{
		t1->r = merge(t1->r, t2);
		calc(t1);
		return t1;
	}
	else
	{
		t2->l = merge(t1, t2->l);
		calc(t2);
		return t2;
	}
}

void split(node *t, node *&t1, node *&t2, ll x)
{
	if (t == nullptr) 
	{
		t1 = t2 = nullptr;
		return;
	}
	push(t);
	if (t->x < x)
	{
		split(t->r, t->r, t2, x);
		t1 = t;
	}
	else
	{
		split(t->l, t1, t->l, x);
		t2 = t;
	}

	calc(t);
}
const int MAX_N = 200 * 1000 + 228;

int n;
int arr[MAX_N];

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	
	
	srand(time(NULL));
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

	node *tree = nullptr;
	
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		node *t1, *t2;
		split(tree, t1, t2, arr[i]);
		tree = merge(merge(t1, new_node(arr[i])), t2);

		int x = 0;
		scanf("%d", &x);
		split(tree, t1, t2, x);

		ans = get_sum(t1) + (ll)x * get_sz(t2);
		printf("%lld ", ans);

		tree = t2;
		add(tree, -x);
	}

	return 0;
}