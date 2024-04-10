import std.stdio, std.array, std.range, std.string, std.typecons;
import std.algorithm, std.container, std.math, std.numeric, std.random;
void scan(T...)(ref T args) { foreach (ref arg; args) readf(" %s", &arg); }
void minify(T)(ref T a, in T b) { if (a > b) a = b; }
void maxify(T)(ref T a, in T b) { if (a < b) a = b; }
void ewriteln(T...)(T args) { stderr.writeln("\033[35m", args, "\033[0m"); }
int ilen(T)(const ref T a) { return cast(int)(a.length); }

long r, x, y, xx, yy;
void main() {
	scan(r, x, y, xx, yy);
	writeln(ceil(sqrt(cast(real) (xx - x)^^2 + (yy - y)^^2) / r / 2));
}