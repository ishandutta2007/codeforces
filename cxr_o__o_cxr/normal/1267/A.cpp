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

#define ll long long

const int N = 2e5 + 5;

typedef class Item {
	public:
		ll a, b, t;
		int id;

		void read(int id) {
			this->id = id;
			in >> a >> b >> t;
		}
} Item;

typedef class Comparator1 {
	public:
		boolean operator () (Item a, Item b) {
			return (a.t ^ b.t) ? (a.t < b.t) : (a.id < b.id);
		}
} Comparator1;

typedef class Comparator2 {
	public:
		boolean operator () (Item a, Item b) {
			return ((a.a + a.t) ^ (b.a + b.t)) ? (a.a + a.t < b.a + b.t) : (a.id < b.id);
		}
} Comparator2;

typedef class Event {
	public:
		int op;	// 0 : change, 1 : remove
		int id;
		ll p;

		Event(int op, int id, ll p) : op(op), id(id), p(p) {	}

		boolean operator < (Event b) const {
			return p < b.p;
		}
} Event;

int n;
ll R;
Item a[N];
set<Item, Comparator1> s1;
set<Item, Comparator2> s2;

ll calc(Item x) {
	return max(x.a, R) + x.t;
}

int main() {
//	freopen("a.in", "r", stdin);
	in >> n;
	for (int i = 1; i <= n; i++) {
		a[i].read(i);
	}
	vector<Event> E;
	for (int i = 1; i <= n; i++) {
		E.emplace_back(0, i, a[i].a);
		E.emplace_back(1, i, a[i].b - a[i].t + 1);
//		cerr << a[i].b - a[i].t + 1 << '\n';
		s2.insert(a[i]);
	}
	sort(E.begin(), E.end());
	ll ans = 0;
	vector<Event>::iterator it = E.begin(), _it = E.end();
	while (!s1.empty() || !s2.empty()) {
		ll lim = (it == _it) ? (2e18) : ((*it).p);
//		cerr << R << " " << s1.size() << " " << s2.size() << '\n';
//		if (s1.size() && s2.size())
//			cerr << "qaq:" << calc(*s1.begin()) << " " << calc(*s2.begin()) << '\n';
		if (!s1.empty() && (s2.empty() || calc(*s1.begin()) < calc(*s2.begin()))) {
			ll t = (*s1.begin()).t;
			if (!s2.empty()) {
				Item x = *s2.begin();
				lim = min(lim, x.a + x.t - t + 1);
			}
			ll k = (lim - R + t - 1) / t;
			ans += k;
			R += k * t;
		} else {
			R = calc(*s2.begin());
			ans++;
		}
		while (it != _it && (*it).p <= R) {
			int op = (*it).op;
			int id = (*it).id;
			if (op == 0) {
				s2.erase(a[id]);
				s1.insert(a[id]);
			} else {
				s1.erase(a[id]);
			}
			it++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}