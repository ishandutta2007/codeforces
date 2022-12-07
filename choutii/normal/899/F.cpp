#include <bits/stdc++.h>

#define fir first
#define sec second
#define PB push_back
#define MP make_pair

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234, MaxM = 200;

int n, q; char s[MaxN];
set<int> p[MaxM];

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree <int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

void modify(int p) {
	T.erase(p);		
}

int find(int p) {
	return *T.find_by_order(p - 1);
}

int main() {
	int i;
	n = read(); q = read(); scanf("%s", s + 1);
	for(i = 1; i <= n; i++) 
		p[s[i]].insert(i), T.insert(i);
	while(q--) {
		int l = find(read()), r = find(read()); char s[3], c; scanf("%s", s); c = s[0];
		for(set <int>:: iterator it = p[c].lower_bound(l); it != p[c].end() && *it <= r; p[c].erase(it++)) 
			modify(*it);
	}
	vector<pair<int, int> > ans;
	for(i = 0; i < MaxM; i++)
		for(auto x : p[i])
			ans.PB(MP(x, i));
	sort(ans.begin(), ans.end());
	for(auto x : ans) printf("%c", x.sec);
	return 0;
}