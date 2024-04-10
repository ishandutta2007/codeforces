// ConsoleApplication1.cpp: 
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	struct Node* nodes[2];
}*NodePtr;

struct Node roots[100001];
int exists[100001];

NodePtr ensure(NodePtr node, int i)
{
	if (node->nodes[i] == 0)
	{
		node->nodes[i] = (NodePtr)calloc(1, sizeof(struct Node));
	}
	return node->nodes[i];
}

void add(NodePtr root, int n)
{
	NodePtr trace = root;
	for (int i = 16; i >= 0; i--) {
		trace = ensure(trace, (n & (1 << i)) == 0 ? 0 : 1);
	}
}

int find(NodePtr root, int x, int m, int bit, int cur) {
	if (root == 0 || cur > m) {
		return -1;
	}
	if (bit == -1) {
		return cur;
	}
	if (((1 << bit) & x) == 0) {
		int v = find(root->nodes[1], x, m, bit - 1, cur + (1 << bit));
		if (v == -1) {
			v = find(root->nodes[0], x, m, bit - 1, cur);
		}
		return v;
	}
	else {
		int v = find(root->nodes[0], x, m, bit - 1, cur);
		if (v == -1) {
			v = find(root->nodes[1], x, m, bit - 1, cur + (1 << bit));
		}
		return v;
	}
}
int main() {


	int query;
	scanf("%d", &query);
	for (int i = 1; i <= query; i++) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int a;
			scanf("%d", &a);;
			if (exists[a]) {
				continue;
			}
			exists[a] = 1;

			for (int j = 1; j * j <= a; j++) {
				if (a % j == 0) {
					add(&roots[j], a);
					if (j * j != a) {
						add(&roots[a / j], a);
					}
				}
			}
		}
		else {
			int x, k, s;
			scanf("%d %d %d", &x, &k, &s);

			if (x % k != 0) {
				printf("%d\n", -1);
				continue;
			}

			int m = s - x;
			int max = find(&roots[k], x, m, 16, 0);

			printf("%d\n", max);
		}
	}
	return 0;
}