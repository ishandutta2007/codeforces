#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int module = 1e9+7;

const int M = 10000;
const int N = 500;

struct DSU
{
	int pred[N],rank[N];
	int components, size;

	DSU(int n = 0)
	{
		size = n;
		components = n;
		for (int i=0; i<n; i++)
		{
			pred[i] = i;
			rank[i] = 0;
		}
	}

	DSU(DSU* dsu)
	{
		size = dsu->size;
		components = dsu->components;
		for (int i=0; i<size; i++)
		{
			pred[i] = dsu->pred[i];
			rank[i] = dsu->rank[i];
		}
	}

	inline int getP(int v)
	{
		int cur = v;
		while (pred[cur] != cur)
			cur = pred[cur];
		int root = cur;
		cur = v;
		while (cur != root)
		{
			v = pred[cur];
			pred[cur] = root;
			cur = v;
		}
		return root;
	}

	inline bool unionSet(int v1, int v2)
	{
		v1 = getP(v1);
		v2 = getP(v2);

		if (v1 == v2)return false;

		if (rank[v2] > rank[v1]) swap(v1,v2);
		pred[v2] = v1;
		if (rank[v1] == rank[v2]) rank[v1]++;
		components--;
		return true;
	}
};

int cmpUnionDSU(DSU* a, DSU* b)
{
	DSU* buffer = new DSU(a);
	for (int v1=0; v1<b->size; v1++)
		buffer->unionSet(v1, b->getP(v1));
	int answer = buffer->components;
	delete buffer;
	return answer;
}

int n,m,k;
int e1[M+1],e2[M+1];
DSU* ldsu[M+1];
DSU* rdsu[M+2];

int main()
{
	ios_base::sync_with_stdio(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> e1[i] >> e2[i];
		e1[i]--; e2[i]--;
	}

	ldsu[0] = new DSU(n);
	for (int i=1; i<=m; i++)
	{
		ldsu[i] = new DSU(ldsu[i-1]);
		ldsu[i]->unionSet(e1[i], e2[i]);
	}

	rdsu[m+1] = new DSU(n);
	for (int i=m; i>=1; i--)
	{
		rdsu[i] = new DSU(rdsu[i+1]);
		rdsu[i]->unionSet(e1[i], e2[i]);
	}

	cin >> k;
	for (; k; k--)
	{
		int l,r;
		cin >> l >> r;
		cout << cmpUnionDSU(rdsu[r+1], ldsu[l-1]) << endl;
	}
	return 0;
}