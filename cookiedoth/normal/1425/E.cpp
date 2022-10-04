/*
                                                                                                     
                                             `-:://:::-                                             
                                           `//:-------:/:`                                          
                                          .+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                         .o:--..`` ``..--:o`                                        
                                         .o:--...```..---+/`                                        
                                       `/y+o/---....---:+o.                                         
                                   `...````-os+/:---:/+o/--.`                                       
              `-/+++++/:.      `...`       :h+d+oooo+/+-`   ...                                     
            `/++//:::://++-`....`         -.`//````````:`     `..`                                  
           `o+/::------://o/`           `-` -.          -`       `..`                               
 `---.-o/:./o/::-..``..-      ..  ..            -`        `...       ``..``                
  `....o+:-++/:--.```..-://s.        `-`  .-              -`          `-o: .-//::::/:-`             
          `:s+/:--....-::/+s-`      .-   `-                -`           -///:--------:/:`           
           ./s+//:::::://oo-``..: :::::::-`        `+:--........--:/`          
            .:ooo+++++osso-`    `.:-...`/` ./::-------:/:`   -`         :+--..``````.--:+:...-+:-`  
             `.-/+++++/+-.-`    -.   ``:so:/:--.......--:+`  `-```````o+/+--..`````..--:o/-..:s+:.  
                 ```````:``.. `-`     -` `+:--..`````..--/+-.../.`````..-o:--.......---/o.    `     
                        `:  `:-      -.  .o:--..`` ``..--:o`   `-`      `:o+:--------:+o-`          
                         `-`-...    ..   .o/--...```..--:+/`    `-`     `oy/so/////++o/.`           
                          -/`  `-` `- ``+s/o/:---...---:++.      `-`   .-../d://///:-.`             
                `.---..``-..-    .-/..`````-oo+/:::::/+o+-        `-``-`  `-.  ````                 
             `:++++/+++++-  ..``.-/:`      /y-:/++o++/:.`..`       ./.   `-                         
            -++/::::::://+/..:-``:` ..   `-.`  ```.```    `..`   `..`-` `-                          
       ``  -o//:--....-::/++` -.-`   `-`.-`                 `..`..`  `-.-                           
  -----ss+:++/:--.```..-://s.  /.     `::                    `-:.     ./`                           
  `````/:..+o/::-..``.--:/+s. ..-`   `-``-`                 ..` `-`  `-`-`                          
          `-s+/::-----::/+oo---``-` ..    .:-    ```      .-`     .-.-  `-`                         
           `:oo+//::://+os/..:`..-/:`      :y.-:::::::.`.-`        ./-`  `-`                        
            `./+oooooooo+/.`-    .-:...`.. .//:-------://`        `- `..` `:.                       
              ``.-::::-.``-/`  `-` `-  `oo:+:--.......--:/`      `-    `.:--h.``..```               
                          -.-`.-    .-   `+:--..`````..--//`    `-       /s-//::::::::.             
                         -` `/-      ..  .o:--..`` ``..--:o.```.-        `//:--------://`           
                        -` .-`.-`     -.`-o/--...```..--:+/.``-:....``:-.+:--....`...--:+`          
                       ..`-.   `-.   ``:os:o/:---...---:++.  `-     ``///+:-..``````.--:+-````-.`   
              `.:///////.-`      .:-..` -``-+o+/:::::/+o/.  `-         `:+:-..`````..--:o/:--/ys+-  
            `-++///////+o/. ``....`-.    :` `.:++++++/:.`  .-           -o/---......---/o.   `.`    
           `++//:-----::/+o:..`     .-`   :    ```````    .-           `+so+:--------:++-`          
  `````:-``:o/::-..`..--:/+o`         -.  `-             .-          `../../+o+////+o+:.`           
  -----syo/o+/:--.```..-://s.          .-` `-           .-        `...     ``-:////:-``             
       .` `/s//:--....-::/+s.            -. `-`        .-       `..`                                
           .+o+/:::--:://+s/-..`          .::+y  ```  .-     `..`                                   
            ./oo++////+oso-`   `....       :y-+:::::::/`   ...                                      
             `.:+oooooo/-`         `....-. .//:-------:/:-.`                                        
                ``...``                 /+:+:--.......--:+`                                         
                                         `+:--..`````..--//`                                        
                                         .o:--..`` ``..--:o`                                        
                                         .+/--...```..--:+/`                                        
                                         `-o/:---...---:++.                                         
                                          `-+o+/:---:/+o/.                                          
                                            `.:+oooo+/-.`                                           
                                               ``````                                               
*/
 
#ifdef aimbot
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#endif
 
#define hur(f, g) template<class c> int f(c a) {if (sizeof(c) == 8) return g##ll(a); else return g(a);}
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)
 
/*
	- place bitset modifications here
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <ostream>
#include <istream>
#include <typeinfo>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <limits>
#include <fstream>
#include <array>
#include <list>
#include <bitset>
#include <functional>
#include <random>
#include <cstring>
#include <chrono>
 
#define random escape__from__random__aetuhoetnuhshe
#define mt make_tuple
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define le(v) ((int)v.size())
#define f(i, n) for (int i = 0; i < (n); i++)
#define rof(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define apply(v, act) for (auto &x : v) { act; }
#define log(args...) {string s = #args;deque<string> deq;\
string buf = "";int bal = 0;for (char c : s) {\
if (c == '(' || c == '[' || c == '{') {bal++;\
} else if (c == ')' || c == ']' || c == '}') {\
bal--;} else {if (bal == 0) {if (c == ',') {\
deq.pb(buf);buf = "";} else {if (c != ' ') {\
buf += c;}}}}}if (!buf.empty()) {deq.pb(buf);}\
smart_io::precall_print();smart_io::_print(deq, args);}
 
inline int min(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^x; }
inline int max(const int &x, const int &y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long long min(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^x; }
inline long long max(const long long &x, const long long &y) { return (((y-x)>>(64-1))&(x^y))^y; }
 
#define print    \
smart_io::precall_print(); \
cout,
 
#define scan cin,
 
#ifdef fast_allocator
const int MAXMEM = 200 * 1000 * 1024;
char _memory[MAXMEM];
size_t _ptr = 0;
void* operator new(size_t _x) { _ptr += _x; assert(_ptr < MAXMEM); return _memory + _ptr - _x; }
void operator delete (void*) noexcept {}
#endif
 
using namespace std;
 
char string_in_buffer[(int)260];
 
 
void fast_scan(int &x) { scanf("%d", &x); }
void fast_scan(long long &x) { scanf("%lld", &x); }
void fast_scan(unsigned long long &x) { scanf("%llu", &x); }
void fast_scan(double &x) { scanf("%lf", &x); }
void fast_scan(long double &x) { scanf("%Lf", &x); }
void fast_scan(char &x) {
	scanf("%c", &x);
	if (x == '\n') {
		fast_scan(x);
	}
}
void fast_scan(string &x) {
	scanf("%s", string_in_buffer);
	x = string(string_in_buffer);
}
 
template<class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
	fast_scan(p.first);
	fast_scan(p.second);
}
 
template <class T>
void fast_scan(vector<T> &v) {
	for (auto &x : v) fast_scan(x);
}
 
void fast_print(const int &x) { printf("%d", x); }
void fast_print(const unsigned int &x) { printf("%u", x); }
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const char &x) { printf("%c", x); };
// void fast_print(__int128 x) {
// 	if (x == 0) { fast_print('0'); return; }
// 	if (x < 0) {
// 		fast_print('-');
// 		x = -x;
// 	}
// 	__int128 p = 1;
// 	while (x / (p * 10)) p *= 10;
// 	while (p) {
// 		__int128 symb = x / p;
// 		fast_print((int)symb);
// 		x -= p * symb;
// 		p /= 10;
// 	}
// };
void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const string &x) { printf("%s", x.c_str());}
void fast_print(const char v[]) { fast_print((string)v); }
 
template<class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
	fast_print(p.first);
	fast_print(' ');
	fast_print(p.second);
}
 
template <class T>
void fast_print(const vector<T> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print(' ');
		fast_print(v[i]);
	}
}
 
template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print('\n');
		fast_print(v[i]);
	}
}
 
template <class T>
void fast_print(const T &v) {
	for (const auto &x : v) {
		fast_print(x);
		fast_print(' ');
	}
}
 
 
using namespace std;
 
 
namespace smart_io {
	string print_start = "";
	string sep = " ";
	bool first_print = false;
	
	void precall_print() {
		fast_print(print_start);
		print_start = "\n";
		first_print = true;
	}
	
	void _print(deque<string>) {}
	template<class T, class... Args>
	void _print(deque<string> names, T elem, Args... args) {
		if (!first_print) {
			fast_print("\n");
		} else {
			first_print = false;
		}
		fast_print(names.front());
		fast_print(" = ");
		fast_print(elem);
		names.pop_front();
		_print(names, args...);
	}
} //namespace smart_io
 
 
template <class T>
ostream &operator,(ostream &os, const T &object) {
	if (!smart_io::first_print) {
		fast_print(smart_io::sep);
	} else {
		smart_io::first_print = false;
	}
	fast_print(object);
	return os;
}
 
template <class T>
istream &operator,(istream &is, T &object) {
	fast_scan(object);
	return is;
}
 
namespace random {
	using namespace std::chrono;
	mt19937 rng(duration_cast< milliseconds >(
											  system_clock::now().time_since_epoch()
											  ).count());
	uniform_real_distribution<> prob_dist(0.0, 1.0);
};
#define int long long
namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
	typedef long double ld;
}
 
namespace numbers_operation {
	template<class T>
	inline T floor_mod(T a, const T &b) {
		a %= b;	
		if (a < 0) a += b;
		return a;
	}
}
 
using namespace numbers_operation;
using namespace typedefs;
using namespace random;
 
int solve(vector<int> a, vector<int> d, int n, int k) {
	int rez = 0;
	for (int i = 0; i < n; i++) {
		rez = max(rez, a[i] - d[i]);
	}
	if (k == 0) {
		int S = 0;
		for (int i = n - 1; i >= 0; i--) {
			S += a[i];
			rez = max(rez, S - d[i]);
		}
	} else if (k >= 4) {
		rez = max(rez, accumulate(a.begin(), a.end(), 0LL) - *min_element(d.begin(), d.end() - 1));
	} else if (k == 3) {
		int all = accumulate(a.begin(), a.end(), 0LL);
		for (int i = 0; i < n - 1; i++) {
			if (i == 1) continue;
			rez = max(rez, all - d[i]);
		}
		{
			for (int i = 0; i < n - 1; i++) {
				rez = max(rez, all - a.back() - d[i]);
				rez = max(rez, all - d[i] - d.back());
			}
			int _min = d[1];
			for (int i = 0; i < n; i++) {
				if (n == 4 && i == 0) continue;
				if (i != 1)
				rez = max(rez, all - a[i] - _min);
				if (i != 1) {
					// rez = max(rez, all - a[i] - _min + a[i] - d[i]);
				}
			}
		}
	} else if (k == 2) {
		int all = accumulate(a.begin(), a.end(), 0LL);
		for (int i = 1; i < n - 1; i++) {
			rez = max(rez, all - d[i]);
		}
		{
			for (int i = 0; i < n - 1; i++) {
				rez = max(rez, all - a.back() - d[i]);
			}
			int _min = d[0];
			for (int i = 1; i < n; i++) {
				rez = max(rez, all - a[i] - _min);
				rez = max(rez, all - a[i] - _min + a[i] - d[i]);
			}
		}
	} else if (k == 1) {
		int all = accumulate(a.begin(), a.end(), 0LL);
		{
			vector<int> pr(n);
			vector<int> _min(n, 1e18);
			pr[0] = a[0];
			_min[0] = d[0];
			for (int i = 1; i < n; i++) {
				pr[i] += pr[i - 1] + a[i];
				_min[i] = min(_min[i - 1], d[i]);
			}
 
			int S = 0;
			for (int i = n - 1; i > 0; i--) {
				S += a[i];
				// print max(S - d[i], 0LL), max(0LL, pr[i - 1] - _min[i - 1]);
				rez = max(rez, max(S - d[i], 0LL) + max(0LL, pr[i - 1] - _min[i - 1]));
			}
			for (int i = 0; i < n - 1; i++) {
				rez = max(rez, all - a.back() - d[i]);
			}
			int _min_ = d[0];
			for (int i = 1; i < n - 1; i++) {
				rez = max(rez, all - a[i] - _min_);
				rez = max(rez, all - a[i] - _min_ + a[i] - d[i]);
			}
		}
	}
	return rez;
}
 
signed main() {
	int n, k;
	scan n, k;
	vector<int> a(n);
	scan a;
	vector<int> d(n);
	scan d;
	int rez = solve(a, d, n, k);
	for (int i = 1; i <= min(4LL, k); i++) {
		rez = max(rez, solve(a, d, n, i));
	}
	if (k >= 2) {
		rez = max(rez, solve(a, d, n, 0));
	}
	print rez;
}