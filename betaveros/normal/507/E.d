import std.stdio, std.array, std.range, std.string, std.typecons;
import std.algorithm, std.container, std.math, std.numeric, std.random;
void scan(T...)(ref T args) { foreach (ref arg; args) readf(" %s", &arg); }
void minify(T)(ref T a, in T b) { if (a > b) a = b; }
void maxify(T)(ref T a, in T b) { if (a < b) a = b; }
void ewriteln(T...)(T args) { stderr.writeln("\033[35m", args, "\033[0m"); }
int ilen(T)(const ref T a) { return cast(int)(a.length); }

// ok i'm half asleep this was not a good idea (no pun intended)

struct Edge {
	int v1, v2;
	bool w, u;
}

enum int N = 100008;
enum long OO = 10L ^^ 18;
int n, m;
size_t[][N] graph;
long[N] dist;
size_t[N] parent;

int[N] heap;
size_t[N] invheap;
size_t heaplen;

void hpush(int v) {
	heaplen++;
	heap[heaplen] = v;
	invheap[v] = heaplen;
	percUpIx(heaplen);
}
void hswap(size_t i1, size_t i2) {
	swap(heap[i1], heap[i2]);
	swap(invheap[heap[i1]], invheap[heap[i2]]);
}
void percUpIx(size_t ix) {
	if (ix == 1) return;
	size_t parent = ix / 2;
	if (dist[heap[parent]] > dist[heap[ix]]) {
		hswap(parent, ix);
		percUpIx(parent);
	}
}
void percDownIx(size_t ix) {
	size_t tgt = ix;
	foreach (tix; tuple(2*ix, 2*ix + 1)) {
		if (tix <= heaplen && dist[heap[tix]] < dist[heap[tgt]]) {
			tgt = tix;
		}
	}
	if (tgt != ix) {
		hswap(tgt, ix);
		percDownIx(tgt);
	}
}
void percUp(int v) { percUpIx(invheap[v]); }
int hpop() {
	assert(heaplen > 0);
	int ret = heap[1];
	hswap(1, heaplen);
	heaplen--;
	percDownIx(1);
	return ret;
}

Edge[N] edges;

bool[N] vis;

void printDiff() {
	int v = n;
	while (v != 1) {
		auto ei = parent[v];
		edges[ei].u = true;
		Edge e = edges[ei];
		e.u = true;
		assert(v == e.v1 || v == e.v2);
		v = e.v1 ^ e.v2 ^ v;
	}
	int count = 0;
	foreach (ei; 0..m) {
		Edge e = edges[ei];
		if (e.w ^ e.u) {
			count++;
		}
	}
	writeln(count);
	foreach (ei; 0..m) {
		Edge e = edges[ei];
		if (e.w ^ e.u) {
			writeln(e.v1, " ", e.v2, " ", e.u ? 1 : 0);
		}
	}
}

void main() {
	scan(n, m);
	foreach (i; 0..m) {
		int a, b, w;
		scan(a, b, w);
		edges[i] = Edge(a, b, cast(bool)w, false);
		graph[a] ~= i;
		graph[b] ~= i;
	}
	foreach (v; 2..n+1) {
		dist[v] = OO;
	}
	hpush(1);
	while (true) {
		int nxt = hpop();
		vis[nxt] = true;
		if (nxt == n) {
			printDiff();
			return;
		}
		foreach (ei; graph[nxt]) {
			Edge e = edges[ei];
			assert(nxt == e.v1 || nxt == e.v2);
			int other = e.v1 ^ e.v2 ^ nxt;
			long newdist = dist[nxt] + N + (e.w ? -1 : 1);
			if (newdist < dist[other]) {
				parent[other] = ei;
				if (dist[other] == OO) {
					dist[other] = newdist;
					hpush(other);
				} else {
					dist[other] = newdist;
					percUp(other);
				}
			}
		}
	}
}