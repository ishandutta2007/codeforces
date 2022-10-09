#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstdio>


using namespace std;

struct node
{
	pair<int, int> mx;
	node* l;
	node* r;
};

typedef node* tree;

const int M = 40000043;

node buf[M];
int last = 0;

tree newNode(pair<int, int> s, tree left, tree right)
{
	buf[last].mx = s;
	buf[last].l = left;
	buf[last].r = right;
	return &buf[last++];
}

tree make(pair<int, int> val)
{
	return newNode(val, NULL, NULL);
}

tree combine(tree left, tree right)
{
	return newNode(max(left->mx, right->mx), left, right);
}

tree build(const vector<pair<int, int> >& a, int l, int r)
{
	if (l == r - 1)
		return make(a[l]);
	else
	{
		int m = (l + r) / 2;
		tree left = build(a, l, m);
		tree right = build(a, m, r);
		return combine(left, right);
	}
}

tree upd(tree t, int l, int r, int pos, pair<int, int> val)
{
	if (l == r - 1)
		return make(val);
	int m = (l + r) / 2;
	tree left = t->l;
	tree right = t->r;
	if (pos < m)
		left = upd(left, l, m, pos, val);
	else
		right = upd(right, m, r, pos, val);
	return combine(left, right);
}

pair<int, int> get(tree t, int l, int r, int L, int R)
{
	if (!t || L >= R)
		return { -1, -1 };
	if (l == L && r == R)
		return t->mx;
	int m = (l + r) / 2;
	return max(get(t->l, l, m, L, min(R, m)), get(t->r, m, r, max(m, L), R));
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	//     
	map<int, int> last;
	vector<int> nxt(n);
	for (int i = n - 1; i >= 0; i--)
	{
		int c = a[i];
		if (!last.count(c))
			nxt[i] = n;
		else
			nxt[i] = last[c];
		last[c] = i;
	}
	tree curT = build(vector<pair<int, int> >(n, make_pair(-1, -1)), 0, n);
	set<int> used;
	for(int i = 0; i < n; i++)
		if (!used.count(a[i]))
		{
			used.insert(a[i]);
			curT = upd(curT, 0, n, i, make_pair(nxt[i], i));
		}
	vector<tree> versions = { curT };
	for (int i = 0; i < n; i++)
	{
		curT = upd(curT, 0, n, i, { -1, -1 });
		if (nxt[i] < n)
			curT = upd(curT, 0, n, nxt[i], { nxt[nxt[i]], nxt[i] });
		versions.push_back(curT);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		--l;
		pair<int, int> ans = get(versions[l], 0, n, l, r);
		if (ans.first >= r)
			printf("%d\n", a[ans.second]);
		else
			printf("0\n");
	}
}