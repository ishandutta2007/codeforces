#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1100000 * 2;

struct node
{
	int maxV;
	long long cnt;
	node *go[26], *suf, *next;
};

node Memory[MAXN], *last, *root, *firPos[MAXN];
int cnt, len, n;
char str[3000000];

node *CreatNode(int val)
{
	node *tmp = &Memory[++cnt];
	for(int i = 0; i < 26; ++i) {
		tmp->go[i] = NULL;
	}
	tmp->cnt = 0;
	tmp->maxV = val;
	tmp->next = firPos[val];
	firPos[val] = tmp;
	return tmp;
}

void init()
{	
	for(int i = 0; i <= len; ++i) {
		firPos[i] = NULL;
	}
	cnt = 0;
	root = last = CreatNode(0);

}

void extend(int w)
{
	node *np = CreatNode(last->maxV + 1);
	np->cnt = 1;
	node *p = last;
	while(p && !p->go[w]) {
		p->go[w] = np;
		p = p->suf;
	}
	if (!p) {
		np->suf = root;
	} else {
		node *q = p->go[w];
		if (q->maxV == p->maxV + 1) {
			np->suf = q;
		} else {
			node *nq = CreatNode(p->maxV + 1);
			memcpy(nq->go, q->go, sizeof nq->go);
			nq->suf = q->suf;
			q->suf = nq;
			np->suf = nq;
			for (; p && p->go[w] == q; p = p->suf)
				p->go[w] = nq;
		}
	}
	last = np;
} 

int fail[MAXN];

int KMP(char str[], int len)
{
	fail[0] = -1;
	for(int i = 1; i < len; ++i) {
		int j = fail[i - 1];
		while(j >= 0 && str[j + 1] != str[i]) {
			j = fail[j];
		}
		if (str[j + 1] == str[i])
			fail[i] = j + 1;
		else
			fail[i] = j;
	}
	if (len % (len - fail[len - 1] - 1) == 0)
		return len - fail[len - 1] - 1;
	return len;
}

int main() 
{

	scanf("%s\n", str);
	len = strlen(str);
	init();
	
	for(int i = 0; str[i]; ++i) {
		extend(str[i] - 'a');
	}
	for(int i = len; i >= 0; i--)
		for(node *cur = firPos[i]; cur; cur = cur->next)
		{
			if (cur->suf)
				cur->suf->cnt += cur->cnt;
		}
	int baklen = len;
	scanf("%d\n", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s\n", str);
		len = strlen(str);
		if (baklen < len) {
			printf("0\n");
			continue;	
		}
		int mlen = KMP(str, len);
		//printf("%d\n", mlen);
		for(int j = len; j < 2 * len; ++j) {
			str[j] = str[j - len];
		}
		node *cur = root;
		int match = 0;
		for(int j = 0; j < len - 1; ++j) {
			char w = str[j] - 'a';
			while(cur && !cur->go[w]) {
				cur = cur->suf;
				match = cur ? cur->maxV : 0;
			}
			if (!cur) {
				cur = root;
				match = 0;
			} else {
				cur = cur->go[w];
				match++;
			}
		}
		long long ans = 0;
		for(int j = len - 1; j < len - 1 + mlen; ++j) {
			int w = str[j] - 'a';
			if (match == len) {
				if (match - 1 == cur->suf->maxV)
					cur = cur->suf;
				match--;
			}
			while(cur && !cur->go[w]) {
				cur = cur->suf;
				match = cur ? cur->maxV : 0;
			}
			if (!cur) {
				cur = root;
				match = 0;
			} else {
				cur = cur->go[w];
				match++;
			}
			if (match == len) {
				ans += cur->cnt;
			}
		}
		cout << ans << endl;
	}
//	system("pause");
	return 0;
}