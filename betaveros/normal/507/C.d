import std.stdio, std.array, std.range, std.string, std.typecons;
import std.algorithm, std.container, std.math, std.numeric, std.random;
void scan(T...)(ref T args) { foreach (ref arg; args) readf(" %s", &arg); }
void minify(T)(ref T a, in T b) { if (a > b) a = b; }
void maxify(T)(ref T a, in T b) { if (a < b) a = b; }
void ewriteln(T...)(T args) { stderr.writeln("\033[35m", args, "\033[0m"); }
int ilen(T)(const ref T a) { return cast(int)(a.length); }

int h; ulong n;
void main() {
	scan(h, n);
	n = (n - 1) | (1L << h);
	ulong res = 0;
	foreach (i; 0..h) {
		if (((n >> i) ^ (n >> (i + 1))) & 1) {
			res += 1;
		} else {
			res += 1L << (i + 1);
		}
	}
	writeln(res);
}