#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Input {
	protected:
		const static int limit = 65536;
		FILE* file; 

		int ss, st;
		char buf[limit];
	public:
		
		Input() : file(NULL)	{	};
		Input(FILE* file) : file(file) {	}

		void open(FILE *file) {
			this->file = file;
		}

		void open(const char* filename) {
			file = fopen(filename, "r");
		}

		char pick() {
			if (ss == st)
				st = fread(buf, 1, limit, file), ss = 0;//, cerr << "str: " << buf << "ed " << st << endl;
			return (ss == st) ? (-1) : (buf[ss++]);
		}
} Input;

#define digit(_x) ((_x) >= '0' && (_x) <= '9')

Input& operator >> (Input& in, unsigned& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, unsigned long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	return in;
}

Input& operator >> (Input& in, int& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, long long& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, double& u) {
	char x;
	while (~(x = in.pick()) && !digit(x) && x != '-');
	int aflag = ((x == '-') ? (x = in.pick(), -1) : (1));
	for (u = x - '0'; ~(x = in.pick()) && digit(x); u = u * 10 + x - '0');
	if (x == '.') {
		double dec = 1;
		for ( ; ~(x = in.pick()) && digit(x); u = u + (dec *= 0.1) * (x - '0'));
	}
	u *= aflag;
	return in;
}

Input& operator >> (Input& in, char* str) {
	char x;
	while (~(x = in.pick()) && x != '\n' && x != ' ')
		*(str++) = x;
	*str = 0;
	return in;
}

Input in (stdin);

typedef class Output {
	protected:
		const static int Limit = 65536;
		char *tp, *ed;
		char buf[Limit];
		FILE* file;
		int precision;

		void flush() {
			fwrite(buf, 1, tp - buf, file);
			fflush(file);
			tp = buf;
		}

	public:

		Output() {	}
		Output(FILE* file) : tp(buf), ed(buf + Limit), file(file), precision(6) {	}
		Output(const char *str) : tp(buf), ed(buf + Limit), precision(6) {
			file = fopen(str, "w");
		}
		~Output() {
			flush();
		}

		void put(char x) {
			if (tp == ed)
				flush();
			*(tp++) = x;
		}

		int get_precision() {
			return precision;
		}
		void set_percision(int x) {
			precision = x;
		}
} Output;

Output& operator << (Output& out, int x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, long long x) {
	static char buf[36];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		if (x < 0)
			out.put('-'), x = -x;
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, unsigned x) {
	static char buf[35];
	static char * const lim = buf + 34;
	if (!x)
		out.put('0');
	else {
		char *tp = lim;
		for ( ; x; *(--tp) = x % 10, x /= 10);
		for ( ; tp != lim; out.put(*(tp++) + '0'));
	}
	return out;
}

Output& operator << (Output& out, char x)  {
	out.put(x);
	return out;
}

Output& operator << (Output& out, const char* str) {
	for ( ; *str; out.put(*(str++)));
	return out;
}

Output& operator << (Output& out, double x) {
	int y = x;
	x -= y;
	out << y << '.';
	for (int i = out.get_precision(); i; i--, y = x * 10, x = x * 10 - y, out.put(y + '0'));
	return out;
}

Output out (stdout);

const int N = 4e6 + 5;

int T, n;
int s[N], c[N];

void solve() {
	in >> n;
	memset(s, 0, sizeof(int) * (n * 2 + 2));
	memset(c, 0, sizeof(int) * (n * 2 + 2));
	for (int i = 1, x; i <= n; i++) {
		in >> x;
		s[x]++;
	}
	int have = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i]) {
			c[s[i]]++;
			have++;
		}
	}
	for (int i = 1; i <= n * 2; i++)
		c[i] += c[i - 1];
	int ans = n;
	for (int s = 2; s <= n; s++) {
		int cnt = 0, fin = 0;
		for (int i = s, t = 1; i <= n + s; i += s, t++) {
			int l = max(i - s, i - t - 1);
			fin += c[i] - c[l];
			cnt += (c[i] - c[l]) * t;
		}
		if (fin == have) {
			ans = min(ans, cnt);
		}
	}
	out << ans << '\n';
}

int main() {
	in >> T;
	while (T--) {
		solve();
	}
	return 0;
}