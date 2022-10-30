#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))
#define mp make_pair

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 15e3+22 ;

int n;
int d[5],m[5][MAXN],st[5][MAXN],qqq[5][MAXN];
set<pair<int,int> >s;

int main() {
	scanf("%d", &n);
	for(int t=1;t<=2;t++) {
		scanf("%d", &d[t]);
		for(int i=1;i<=d[t];i++) scanf("%d", &m[t][i]);
	}

	st[1][0]=-1, st[2][0]=-1;
	s.insert(mp(1, 0)) , s.insert(mp(2, 0));

	while(s.size()) {
		int r=(*s.begin()).first , x=(*s.begin()).second;
		int e=3-r;
		s.erase(s.begin());
		for(int i=1;i<=d[e];i++) {
			int w=(x-m[e][i]+n)%n;
			if(st[r][x]==-1 && st[e][w]==0)
				st[e][w]=1 , s.insert(mp(e, w));
			if(st[r][x]==1) qqq[e][w]++;
			if(st[e][w]==0 && qqq[e][w]==d[e])
				st[e][w]=-1 , s.insert(mp(e, w));
		}
	}

	for(int t=1;t<=2;t++) {
		for(int i=1;i<n;i++)
			if(st[t][i]==-1) cout<<"Lose ";
			else if(st[t][i]==0) cout<<"Loop " ;
			else cout<<"Win ";
		cout<<endl;
	}

	return 0;
}