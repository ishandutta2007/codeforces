#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERSION 100001

typedef struct Node26 {
	struct Node26* children[26];
	int val;
}* Ptr26;
typedef struct Node2 {
	struct Node2* children[2];
	int val;
}* Ptr2;

Ptr26 new26() {
	Ptr26 node = malloc(sizeof(struct Node26));
	node->val = 0;
	memset(node->children, 0, sizeof(Ptr26) * 26);
	return node;
}

Ptr26 clone26(Ptr26 origin) {
	if (origin == 0) {
		return new26();
	}
	Ptr26 node = malloc(sizeof(struct Node26));
	memcpy(node, origin, sizeof(struct Node26));
	return node;
}

Ptr2 new2() {
	Ptr2 node = malloc(sizeof(struct Node2));
	node->val = 0;
	node->children[0] = node->children[1] = 0;
	return node;
}

Ptr2 clone2(Ptr2 origin) {
	if (origin == 0) {
		return new2();
	}
	Ptr2 node = malloc(sizeof(struct Node2));
	memcpy(node, origin, sizeof(struct Node2));
	return node;
}

Ptr26 add26(Ptr26 root, int val, int oldVal[], char data[]) {
	root = clone26(root);
	Ptr26 trace = root;

	for (int i = 0; data[i]; i++) {
		int j = data[i] - 'a';
		trace->children[j] = clone26(trace->children[j]);
		trace = trace->children[j];
	}

	oldVal[0] = trace->val;
	trace->val = val;
	return root;
}

int query26(Ptr26 root, char data[]) {
	root = clone26(root);
	Ptr26 trace = root;

	for (int i = 0; data[i] && trace; i++) {
		int j = data[i] - 'a';
		trace = trace->children[j];
	}

	return trace == 0 ? 0 : trace->val;
}

Ptr2 add2(Ptr2 root, int x, int v) {
	root = clone2(root);
	Ptr2 trace = root;
	for (int i = 29; i >= 0; i--) {
		int bit = (x >> i) & 1;
		trace->val += v;
		trace->children[bit] = clone2(trace->children[bit]);
		trace = trace->children[bit];
	}
	trace->val += v;
	return root;
}

Ptr2 query2(Ptr2 root, int x) {
	Ptr2 trace = root;
	int sum = 0;
	for (int i = 29; i >= 0; i--) {
		int bit = (x >> i) & 1;
		if (bit && trace->children[0]) {
			sum += trace->children[0]->val;
		}
		trace = trace->children[bit];
	}
	return sum;
}

Ptr26 version26[MAX_VERSION];
Ptr2 version2[MAX_VERSION];
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\DataBase\\TESTCASE\\codeforces\\JamieandTodoList.in", "r",
	stdin);
#endif

	int p;
	int oldValue;
	int value;
	char s[64];
	scanf("%d", &p);

	version26[0] = new26();
	version2[0] = new2();
	for (int i = 1; i <= p; i++) {
		scanf("%s", s);
		version26[i] = version26[i - 1];
		version2[i] = version2[i - 1];
		switch (s[0]) {
		case 's': {
			//set operation
			scanf("%s %d", s, &value);
			//Now cmd container the name of task
			version26[i] = add26(version26[i], value, &oldValue, s);
			if (oldValue > 0) {
				version2[i] = add2(version2[i], oldValue, -1);
			}
			version2[i] = add2(version2[i], value, 1);
		}
			break;
		case 'r': {
			//remove operation
			scanf("%s", s);
			version26[i] = add26(version26[i], -1, &oldValue, s);
			if (oldValue > 0) {
				version2[i] = add2(version2[i], oldValue, -1);
			}
		}
			break;
		case 'q': {
			//query operation
			scanf("%s", s);
			int priority = query26(version26[i], s);
			int prefixSum = priority > 0 ? query2(version2[i], priority) : -1;
			printf("%d\n", prefixSum);
			fflush(stdout);
		}
			break;
		case 'u': {
			scanf("%d", &value);
			version26[i] = version26[i - value - 1];
			version2[i] = version2[i - value - 1];
		}
			break;
		}
	}
	return 0;
}