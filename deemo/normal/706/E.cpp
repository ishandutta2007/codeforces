#include<bits/stdc++.h>

using namespace std;

#define F first
#define up asdf
#define down lkjasdf
#define left lkhasdf
#define right uajs

const int MAXN = 1e3 + 10;

struct Node{
	int id, val;
	int up, down, left, right;
	Node(){
		up = down = left = right = -1;
	}
};

int n, m, q;
Node v[MAXN * MAXN], t[MAXN * MAXN];

int main(){
	scanf("%d %d %d", &n, &m, &q);
	n += 2, m += 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i * m + j].id = i * m + j;
	for (int i = 1; i + 1 < n; i++)
		for (int j = 1; j + 1 < m; j++)
			scanf("%d", &v[i * m + j].val);
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			v[i * m + j].up = v[(i - 1) * m + j].id;
	for (int i = 0; i + 1 < n; i++)
		for (int j = 0; j < m; j++)
			v[i * m + j].down = v[(i + 1) * m + j].id;
	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++)
			v[i * m + j].left = v[i * m + (j - 1)].id;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + 1 < m; j++)
			v[i * m + j].right = v[i * m + (j + 1)].id;

	while (q--){
		int a, b, c, d, x, y;	
		scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &x, &y);
		int id1 = 0, id2 = 0;
		for (int i = 0; i < a; i++)	id1 = v[id1].down;
		for (int i = 0; i < b; i++)	id1 = v[id1].right;
		for (int i = 0; i < c; i++)	id2 = v[id2].down;
		for (int i = 0; i < d; i++)	id2 = v[id2].right;

		int cur1 = id1, cur2 = id2;
		for (int j = 0; j < y; j++){
			swap(v[cur1].up, v[cur2].up);
			v[v[cur1].up].down = cur1;
			v[v[cur2].up].down = cur2;

			cur1 = v[cur1].right;
			cur2 = v[cur2].right;
		}

		cur1 = id1, cur2 = id2;
		for (int i = 0; i < x; i++){
			swap(v[cur1].left, v[cur2].left);
			v[v[cur1].left].right = cur1;
			v[v[cur2].left].right = cur2;
			
			cur1 = v[cur1].down;
			cur2 = v[cur2].down;
		}

		for (int j = 0; j < y - 1; j++){
			id1 = v[id1].right;
			id2 = v[id2].right;
		}
		cur1 = id1, cur2 = id2;
		for (int i = 0; i < x; i++){
			t[cur1] = v[cur1];
			t[cur2] = v[cur2];
			swap(v[cur1].right, v[cur2].right);
			v[v[cur1].right].left = cur1;
			v[v[cur2].right].left = cur2;
			
			cur1 = v[cur1].down;
			cur2 = v[cur2].down;
		}

		for (int i = 0; i < x-1; i++){
			id1 = v[id1].down;
			id2 = v[id2].down;
		}

		cur1 = id1, cur2 = id2;
		for (int j = 0; j < y; j++){
			swap(v[cur1].down, v[cur2].down);
			v[v[cur1].down].up = cur1;
			v[v[cur2].down].up = cur2;

			if (j){
				cur1 = v[cur1].left;
				cur2 = v[cur2].left;
			}
			else{
				cur1 = t[cur1].left;
				cur2 = t[cur2].left;
			}
		}
	}
	
	int id = 0;
	id = v[id].down;
	for (int i = 1; i + 1 < n; i++){
		int cur = id;
		cur = v[cur].right;
		for (int j = 1; j + 1 < m; j++){
			printf("%d ", v[cur].val);
			cur = v[cur].right;
		}
		printf("\n");
		id = v[id].down;
	}
	return 0;
}