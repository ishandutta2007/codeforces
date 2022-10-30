import std.algorithm;
import std.array;
import std.stdio;
import std.typecons;
immutable int N = 2 ^^ 16 + 8;
int[N] deg, s;
int n;
int[] d1;
Tuple!(int, int)[] edges;
void main() {
	scanf("%d", &n);
	foreach (i; 0..n) {
		scanf("%d%d", &deg[i], &s[i]);
		if (deg[i] == 1) d1 ~= i;
	}
	while (!d1.empty()) {
		int i = d1.back(); // this and next are UFCS for std.array
		d1.popBack();
		if (deg[i] == 0) continue;
		assert(deg[i] == 1);
		deg[i] = 0;
		int j = s[i];
		deg[j] -= 1;
		if (deg[j] == 1) d1 ~= j;
		s[j] ^= i;
		edges ~= tuple(i, j);
	}
	writefln("%d", edges.length);
	foreach (t; edges) {
		writefln("%d %d", t[0], t[1]);
	}
}