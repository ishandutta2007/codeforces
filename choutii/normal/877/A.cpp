#include <bits/stdc++.h>

#define fir first
#define sec second
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

string s;
 
int main() {
	int i;
	cin >> s;
	int cnt = 0;
	for(i = 0; i < s.size(); i++) {
		cnt += (s.substr(i, 5) == "Danil");
		cnt += (s.substr(i, 4) == "Olya");
		cnt += (s.substr(i, 5) == "Slava");
		cnt += (s.substr(i, 3) == "Ann");
		cnt += (s.substr(i, 6) == "Nikita");
	} 
	if(cnt != 1) puts("NO");
	else puts("YES"); 
	return 0;
}