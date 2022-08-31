#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

//hash with overflow
LL BASE[400005];

int n, d;
char ch[400005];

struct BIT
{
	LL dat[400005];
	void add(int id, LL val)
	{
		val *= BASE[id];
		id ++;
		while(id <= n) {
			dat[id] += val;
			id += id & (-id);
		}
	}
	LL query(int id)
	{
		id ++;
		LL ret = 0;
		while(id > 0) {
			ret += dat[id];
			id -= id & (-id);
		}
		return ret;
	}
}hs, rhs;

inline bool ispal(int l, int r)
{
	LL hv = hs.query(r) - hs.query(l - 1);
	LL rhv = rhs.query(n - l - 1) - rhs.query(n - r - 2);
	return hv * BASE[n - r - 1] == rhv * BASE[l];
}
inline void add_h(int pos, int d = 1)
{
	hs.add(pos, d);
	rhs.add(n - pos - 1, d);
}
inline bool collis(int pos)
{
	return (pos >= d - 1 && ispal(pos - d + 1, pos)) || (pos >= d && ispal(pos - d, pos));
}

int main()
{
	scanf("%d%s", &d, ch);
	n = strlen(ch);
	BASE[0] = 1;
	rep(i, n) BASE[i + 1] = BASE[i] * 3;
	rep(i, n) {
		hs.add(i, ch[i]);
		rhs.add(i, ch[n - i - 1]);
	}
	int pos = 0;
	for(; pos < n - 1 && !collis(pos); pos ++) ;
	for(; pos >= 0; pos --) {
		for(ch[pos] ++; ch[pos] <= 'z'; ch[pos] ++) {
			add_h(pos);
			if(!collis(pos)) {
				for(pos ++; pos < n; pos ++) {
					add_h(pos, 'a' - ch[pos]);
					ch[pos] = 'a';
					for(; ch[pos] <= 'z'; ch[pos] ++) {
						if(!collis(pos)) break;
						add_h(pos);
					}
				}
				printf("%s", ch);
				return 0;
			}
		}
		add_h(pos);
	}
	printf("Impossible");
	return 0;
}