#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 1234;
vector<pair<int, int> > ans;
string s, t; int a[MaxN];

int main() {
	int i;
	cin >> s >> t;
	int n = s.size();
	memset(a, -1, sizeof(a));
	for(i = 0; i < s.size(); i++)
		if(! ~a[s[i]] || a[s[i]] == t[i]) {
			if(! ~a[s[i]])
				s += t[i], t += s[i];
			a[s[i]] = t[i];
		}else return puts("-1"), 0;
	for(i = 'a'; i <= 'z'; i++) {
		if(!~a[i]) a[i] = i;
		if(a[i] != i) {
			if(a[a[i]] != i) return puts("-1"), 0;
			if(a[i] > i) ans.push_back(make_pair(i, a[i])); 
		}
	}
	
	cout << ans.size() << endl;
	for(auto p : ans)
		cout << (char)p.fir << " " << (char)p.sec << endl;
	return 0;
}