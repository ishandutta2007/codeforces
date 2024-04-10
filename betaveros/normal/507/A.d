import std.stdio, std.array, std.range, std.string, std.typecons;
import std.algorithm, std.container, std.math, std.numeric, std.random;
void scan(T...)(ref T args) { foreach (ref arg; args) readf(" %s", &arg); }
void minify(T)(ref T a, in T b) { if (a > b) a = b; }
void maxify(T)(ref T a, in T b) { if (a < b) a = b; }
void ewriteln(T...)(T args) { stderr.writeln("\033[35m", args, "\033[0m"); }
int ilen(T)(const ref T a) { return cast(int)(a.length); }

// wow, 32/64 architectures
Tuple!(int,size_t)[] a;
void main() {
	size_t n; int k;
	scan(n, k);
	foreach(i; 1..n+1) {
		int x;
		scan(x);
		a ~= tuple(x, i);
	}
	sort(a);
	size_t s = n;
	foreach(i, e; a) {
		k -= e[0];
		if (k < 0) { s = i; break; }
	}
	writeln(s);
	foreach (i; 0..s) {
		if (i) write(" ");
		write(a[i][1]);
	}
	writeln();
}