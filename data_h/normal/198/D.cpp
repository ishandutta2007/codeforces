#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

const int N = 2e2 + 7;

int cube[N][N][N];

struct Node {
	int x, y, z;
	Node() {}
	Node(int x, int y, int z) : x(x), y(y), z(z) {

	}
};

Node queue[N * N * N * 2];
int n;

void set(Node& a, int v) {
	int X = 100, Y = 100;
	cube[X + a.x][Y + a.y][a.z] = v;
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	if (n == 2) {
		printf("1 2\n");
		printf("4 3\n");
		puts("");
		printf("8 7\n");
		printf("5 6\n");
		return 0;
	}
	int xp = 2, yp = 3, tail = N * N * N, head = tail;
	queue[head] = Node(1, 3, 2);
	queue[++tail] = Node(2, 3, 2);
	queue[++tail] = Node(2, 3, 1);
	queue[++tail] = Node(1, 3, 1);
	queue[++tail] = Node(1, 2, 1);
	queue[++tail] = Node(1, 2, 2);
	queue[++tail] = Node(2, 2, 2);
	queue[++tail] = Node(2, 2, 1);
	queue[++tail] = Node(2, 1, 1);
	queue[++tail] = Node(1, 1, 1);
	queue[++tail] = Node(1, 1, 2);
	queue[++tail] = Node(2, 1, 2);

	for (int h = 3; h <= n; h++) {
		if (xp > yp) {
			for (int i = xp; i >= 1; i--) {
				queue[++tail] = Node(i, 1, h);
			}
			for (int i = 1; i < xp; i += 2) {
				for (int j = yp; j > 1; j--) {
					queue[--head] = Node(i, j, h);
				}
				for (int j = 2; j <= yp; j++) {
					queue[--head] = Node(i + 1, j, h);
				}
			}
			for (int i = head; i <= tail; i++) queue[i].y++;
			yp += 2;
			for (int i = 1; i < xp; i += 2) {
				for (int j = h; j >= 1; j--) {
					queue[++tail] = Node(i, 1, j);
				}
				for (int j = 1; j <= h; j++) {
					queue[++tail] = Node(i + 1, 1, j);
				}
			}
			for (int i = xp; i > 1; i -= 2) {
				for (int j = h; j >= 1; j--) {
					queue[--head] = Node(i, yp, j);
				}
				for (int j = 1; j <= h; j++) {
					queue[--head] = Node(i - 1, yp, j);
				}
			}
		} else if (xp < yp) {
			for (int i = 1; i <= yp; i++) {
				queue[++tail] = Node(xp, i, h);
			}
			for (int i = 1; i < xp; i++) {
				queue[--head] = Node(i, yp, h);
			}
			for (int i = yp - 1; i >= 1; i--) {
				queue[--head] = Node(xp - 1, i, h);
			}
			for (int i = xp - 2; i > 1; i -= 2) {
				for (int j = 1; j < yp; j++) {
					queue[--head] = Node(i, j, h);
				}
				for (int j = yp - 1; j >= 1; j--) {
					queue[--head] = Node(i - 1, j, h);
				}
			}
			for (int i = head; i <= tail; i++) queue[i].x++;
			xp += 2;
			for (int i = yp, cur = 0; i >= 1; i--, cur ^= 1) {
				for (int j = h; j >= 1 && cur == 0; j--) {
					queue[++tail] = Node(xp, i, j);
				}
				for (int j = 1; j <= h && cur == 1; j++) {
					queue[++tail] = Node(xp, i, j);
				}
			}
			for (int i = 1, cur = 0; i <= yp; i++, cur ^= 1) {
				for (int j = h; j >= 1 && cur == 0; j--) {
					queue[--head] = Node(1, i, j);
				}
				for (int j = 1; j <= h && cur == 1; j++) {
					queue[--head] = Node(1, i, j);
				}
			}
			for (int i = head; i <= tail; i++) {
				queue[i].z = h - queue[i].z + 1;
			}
		}
		//assert(tail - head + 1 == h * h * (h + 1));
	}
/*			for (int i = head; i <= tail; i++) {
				printf("(%d, %d, %d)\n", queue[i].x, queue[i].y, queue[i].z);
			}
			puts("");

			printf("%d\n", tail - head + 1);
*/
	for (int i = head, tot = 0; i <= tail; i++) {
		Node t = queue[i];
		if (t.x > n || t.y > n || t.z > n) {
			//cout << "fuck you " << t.x << " " << t.y << " " << t.z << endl;
		} else {
			cube[t.x][t.y][t.z] = ++tot;
		}
	}
	for (int i = 1; i <= n; i++, puts("")) {
		for (int j = 1; j <= n; j++, printf("\n")) {
			for (int k = 1; k <= n; k++) {
				printf("%d ", cube[j][k][i]);
			}
		}
	}
	return 0;
}