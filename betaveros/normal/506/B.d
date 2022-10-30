import std.stdio, std.array, std.range, std.string, std.typecons;
import std.algorithm, std.container, std.math, std.numeric, std.random;
void scan(T...)(ref T args) { foreach (ref arg; args) scanf("%d", &arg); }
void minify(T)(ref T a, in T b) { if (a > b) a = b; }
void maxify(T)(ref T a, in T b) { if (a < b) a = b; }
void ewriteln(T...)(T args) { stderr.writeln("\033[35m", args, "\033[0m"); }
int ilen(T)(const ref T a) { return cast(int)(a.length); }
void push(T)(ref Array!T a, in T b) {
	// if (a.length == a.capacity) a.reserve(2*a.capacity + 1);
	a ~= b;
}

enum int N = 10 ^^ 5 + 8;
int n, m;
Array!int[N] graph;
Array!int[N] antigraph;
int[N] outdeg;
bool[N] vis;
Array!int curv;
int cost = 0;

void dfs(int v) {
	if (vis[v]) return;
	curv.push(v);
	vis[v] = true;
	foreach (w; graph[v]) { dfs(w); }
	foreach (w; antigraph[v]) { dfs(w); }
}

Array!int out0;
void solveFrom(int v0) {
	if (!vis[v0]) {
		curv.length = 0;
		dfs(v0);
		out0.length = 0;
		debug {
			ewriteln("solving from: ", v0);
			ewriteln("  curv cap ", curv.capacity);
			ewriteln("  out0 cap ", out0.capacity);
		}
		int ovs = 0;
		foreach (v; curv) {
			outdeg[v] = graph[v].ilen;
			if (outdeg[v] == 0) {
				out0.push(v);
				ovs++;
			}
		}
		while (!out0.empty) {
			int v = out0.back; out0.removeBack();
			foreach (w; antigraph[v]) {
				assert(outdeg[w] >= 1);
				outdeg[w]--;
				if (outdeg[w] == 0) {
					out0.push(w);
					ovs++;
				}
			}
		}
		cost += ovs == curv.ilen ? curv.ilen - 1 : curv.ilen;
	}
}

int solve() {
	foreach (i; 1..n+1) { solveFrom(i); }
	return cost;
}

void main() {
	scan(n, m);
	foreach(_; 0..m) {
		int a, b;
		scan(a, b);
		graph[a].push(b);
		antigraph[b].push(a);
	}
	writeln(solve());
}