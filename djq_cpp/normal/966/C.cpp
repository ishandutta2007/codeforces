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
const int INF = 1e9 + 7;

struct node
{
	node* son[2];
	int sz;
	node()
	{
		sz = 0;
		son[0] = son[1] = NULL;
	}
};
node* tr[64];

int highbit(LL x)
{
	return 63 - __builtin_clzll(x);
}

int getsiz(node* x)
{
	return x == NULL ? 0 : x -> sz;
}

void insert_v(node*& cur, LL dat, int dig = 59)
{
	if(cur == NULL) cur = new node();
	if(dig >= 0) {
		insert_v(cur -> son[(dat >> dig) & 1], dat, dig - 1);
		cur -> sz = getsiz(cur -> son[0]) + getsiz(cur -> son[1]);	
	} else cur -> sz ++;
}

LL least(node* cur, LL xo, int dig = 59)
{
	if(dig >= 0) {
		bool cbit = (xo >> dig) & 1;
		if(cur -> son[cbit] != NULL) return least(cur -> son[cbit], xo, dig - 1);
		else return least(cur -> son[!cbit], xo, dig - 1) ^ (1LL << dig);
	} else return 0;
}

void erase_v(node*& cur, LL dat, int dig = 59)
{
	if(dig >= 0) {
		erase_v(cur -> son[(dat >> dig) & 1], dat, dig - 1);
		cur -> sz = getsiz(cur -> son[0]) + getsiz(cur -> son[1]);
	} else cur -> sz --;
	if(cur -> sz == 0) cur = NULL;
}

vector<LL> ans;

int main()
{
	int n;
	LL x;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%I64d", &x);
		insert_v(tr[highbit(x)], x);
	}
	x = 0LL;
	rep(i, n) {
		bool fl = false;
		rep(j, 60) if(!((x >> j) & 1) && getsiz(tr[j])) {
			LL cur = least(tr[j], x);
			cur ^= x;
			x ^= cur;
			erase_v(tr[j], cur);
			ans.push_back(cur);
			fl = true;
			break;
		}
		if(!fl) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	rep(i, n) printf("%I64d ", ans[i]);
	return 0;
}