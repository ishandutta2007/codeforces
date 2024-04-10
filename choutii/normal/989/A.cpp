#include <bits/stdc++.h>

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()
#define debug(x) cerr << #x" = " << x << endl

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T, typename TT> ostream & operator << (ostream &out, pair<T, TT> t) { return out << "(" << t.X << "," << t.Y << ")";}
template <typename T> ostream & operator << (ostream &out,vector<T> t) { out << "["; for (auto x:t) out << x << " "; out << "]"; return out;}
template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
template <typename T> void read(T & x) {
	int f = 1; char ch; x = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); x *= f;
}

const int NX = 105;

char s[NX]; int a[NX], m[NX], n;
int main() {
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; i++) {
		int u = s[i] - 'A';
		if(s[i] == '.') continue;
		if(i) m[i - 1] |= (1 << u);
		if(i + 1 < n)
			m[i + 1] |= (1 << u);
		m[i] |= (1 << u);
	}
	for (int i = 0; i < n; i++) {
		if (m[i] == (1 << 3) - 1)	
			return puts("Yes"), 0;	
	}
	
	puts("No");
	return 0;
}


// hack it