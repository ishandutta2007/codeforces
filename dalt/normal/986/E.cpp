#if (defined CF986E) || (defined ONLINE_JUDGE)

#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<complex>
#include<stdio.h>
#include<limits.h>
#include<algorithm>
#include<ctime>

#define INF 100000000
#define SWAP(a, b, type) {type _tmp = a; a = b; b = _tmp;}
#define PI 3.14159265358979323846
#define ll long long
#define ull unsigned long long
#define ld long double
#define uint unsigned int

#ifndef LLONG_MAX 
#define LLONG_MAX 0x7fffffffffffffffLL
#endif
#ifndef LLONG_MIN
#define LLONG_MIN (-LLONG_MAX - 1)
#endif

//Math functions
namespace mathematic {

	int intRound(double x) {
		return int(x + 0.5);
	}
	int intRound(float x) {
		return int(x + 0.5);
	}

	int numberOfLeadingZero(unsigned int i)
	{
		// HD, Figure 5-6
		if (i == 0)
			return 32;
		int n = 1;
		if (i >> 16 == 0) { n += 16; i <<= 16; }
		if (i >> 24 == 0) { n += 8; i <<= 8; }
		if (i >> 28 == 0) { n += 4; i <<= 4; }
		if (i >> 30 == 0) { n += 2; i <<= 2; }
		n -= i >> 31;
		return n;
	}

	int floorLog2(int x)
	{
		return 31 - numberOfLeadingZero(x);
	}

	int ceilLog2(int x)
	{
		return 32 - numberOfLeadingZero(x - 1);
	}

	template<class T> inline T &min(T&a, T&b) {
		return a <= b ? a : b;
	}

	template<class T> inline const T & min(const T & a, const T & b) {
		return a <= b ? a : b;
	}

	template<class T> inline T &max(T&a, T&b) {
		return a >= b ? a : b;
	}

	template<class T> inline const T &max(const T &a, const T &b) {
		return a >= b ? a : b;
	}

	ull pow(uint x, int n, int mod) {
		int bit = floorLog2(n);
		ull product = 1;
		for (; bit >= 0; bit--) {
			product = product * product % mod;
			if (((1 << bit) & n) != 0) {
				product = product * x % mod;
			}
		}

		return product;
	}

	ull gcd0(ull a, ull b)
	{
		return b == 0 ? a : gcd0(b, a % b);
	}

	ull gcd(ull a, ull b)
	{
		return a >= b ? gcd0(a, b) : gcd0(b, a);
	}

	uint gcd(uint a, uint b)
	{
		return a >= b ? gcd0(a, b) : gcd0(b, a);
	}

	uint gcd0(uint a, uint b)
	{
		return b == 0 ? a : gcd0(b, a % b);
	}
}

//Segment
namespace rmq {

	typedef struct _Segment *Segment;
	struct _Segment {
		int left;
		int right;
		int val;
	} segments[35000000];
	int segmentsHead = 0;
	int newSegment() {
		return segmentsHead++;
	}
	int build() {
		int segment = newSegment();
		segments[segment].left = segments[segment].right = segment;
		return segment;
	}
	int query(int segment, int from, int to, int l, int r)
	{
		if (from > r || to < l)
		{
			return 0;
		}
		if (from <= l && to >= r)
		{
			return segments[segment].val;
		}

		int m = (l + r) >> 1;
		return query(segments[segment].left, from, to, l, m)+
			query(segments[segment].right, from, to, m + 1, r);
	}

	int persistentUpdate(int segment, int from, int to, int l, int r, int val)
	{
		if (from > r || to < l)
		{
			return segment;
		}
		int clone = newSegment();
		segments[clone] = segments[segment];
		segment = clone;
		if (from <= l && to >= r)
		{
			segments[segment].val += val;
			return segment;
		}



		int m = (l + r) >> 1;

		segments[segment].left = persistentUpdate(segments[segment].left, from, to, l, m, val);
		segments[segment].right = persistentUpdate(segments[segment].right, from, to, m + 1, r, val);

		return segment;
	}
}



using namespace rmq;

using mathematic::min;
using mathematic::max;
using mathematic::pow;
using std::vector;

class Node {
public:
	vector<Node*> children;
	vector<Node**> task;
	int segment;
	Node* father;
	int val;
	Node*ancestor;
	Node*p;
	int rank;
	bool visited;
	Node() {
		father = NULL;
		segment = -1;
		p = this;
		rank = 0;
		ancestor = NULL;
		visited = false;
	}

	Node*findSet() {
		return p->p == p ? p : (p = p->findSet());
	}

	static void unionSet(Node*a,Node *b) {
		a = a->findSet();
		b = b->findSet();

		if (a == b)
		{
			return;
		}
		if (a->rank == b->rank)
		{
			a->rank++;
		}
		if (a->rank > b->rank)
		{
			b->p = a;
		}
		else {
			a->p = b;
		}
	}
};

/**
* Put all primes less or equal to limit into primes after offset
*/
int eulerSieve(int limit, int* const primes, int *const divisors) {
	char *isComp = new char[limit + 1];
	memset(isComp, 0, sizeof(char) * (limit + 1));
	int wpos = 0;
	divisors[1] = 1;
	divisors[0] = 1;
	for (int i = 2; i <= limit; i++) {
		if (!isComp[i]) {
			primes[wpos++] = i;
			divisors[i] = i;
		}
		for (int j = 0, until = limit / i; j < wpos && primes[j] <= until; j++) {
			int pi = primes[j] * i;
			isComp[pi] = true;
			divisors[pi] = primes[j];
			if (i % primes[j] == 0) {
				break;
			}
		}
	}
	delete[] isComp;
	return wpos - 0;
}


int primes[1000000];
int factors[10000001];
const int RANGE_MIN = 1;
const int RANGE_MAX = 10000000;
const int MOD = 1e9 + 7;
Node nodes[100001];
Node* task[100000][3];
int taskNum[100000];

void tarjan(Node *node, Node *father) {
	node->father = father;
	node->segment = node->father->segment;
	int val = node->val;
	while (val != 1) {
		int factor = factors[val];
		int pro = 1;
		while (val % factor == 0) {
			val /= factor;
			pro *= factor;
			node->segment = persistentUpdate(node->segment, pro, pro, RANGE_MIN, RANGE_MAX, 1);
		}
	}

	node->findSet()->ancestor = node;
	for (int i = 0, until = node->children.size(); i < until; i++)
	{
		Node *child = node->children[i];
		if (child == father) {
			continue;
		}
		tarjan(child, node);
		Node::unionSet(node, child);
		node->findSet()->ancestor = node;
	}

	node->visited = true;
	for (int i = 0, until = node->task.size(); i < until; i++)
	{
		Node**task = node->task[i];
		Node*other = task[0] == node ? task[1] : task[0];
		if (!other->visited)
		{
			continue;
		}
		task[2] = other->findSet()->ancestor;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\CF986E.in", "r", stdin);
	freopen("E:\\DATABASE\\TESTCASE\\codeforces\\CF986E.out", "w", stdout);
#endif


	int primesNum = eulerSieve(RANGE_MAX, primes, factors);

	int n;
	scanf("%d", &n);


	nodes[0].children.push_back(&nodes[1]);
	nodes[0].val = 0;
	for (int i = 1; i < n; i++) {
		int nu, nv;
		scanf("%d %d", &nu, &nv);
		Node& u = nodes[nu];
		Node& v = nodes[nv];
		u.children.push_back(&v);
		v.children.push_back(&u);
	}

	nodes[0].segment = build();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nodes[i].val);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int nu, nv, x;
		scanf("%d %d %d", &nu, &nv, &x);
		task[i][0] = &nodes[nu];
		task[i][1] = &nodes[nv];
		taskNum[i] = x;

		nodes[nu].task.push_back(task[i]);
		nodes[nv].task.push_back(task[i]);
	}

	tarjan(&nodes[1], &nodes[0]);


	for (int i = 0; i < q; i++) {
		Node *u = task[i][0];
		Node *v = task[i][1];
		Node *lca = task[i][2];
		int x = taskNum[i];

		ll product = 1;
		while (x != 1) {
			int factor = factors[x];
			int pro = 1;
			while (x % factor == 0) {
				x /= factor;
				pro *= factor;
			}
			int appearTimes = 0;
			while (pro > 1) {
				int time = query(u->segment, pro, pro, RANGE_MIN, RANGE_MAX)
					+ query(v->segment, pro, pro, RANGE_MIN, RANGE_MAX)
					- query(lca->segment, pro, pro, RANGE_MIN, RANGE_MAX)
					- query(lca->father->segment, pro, pro, RANGE_MIN, RANGE_MAX);
				time -= appearTimes;
				appearTimes += time;

				product = (product * pow(pro, time, MOD)) % MOD;
				pro /= factor;
			}
		}

		printf("%d\n", (int)product);
	}

	return 0;
}

#endif