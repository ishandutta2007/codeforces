#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

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

const int MaxN = 666666;

int n, a[MaxN], b[MaxN];

set<int> gg;
bool in[233333];

int main() {
	srand(19260817);
	int i;
	cin>>n;
	if(n%2==0)
	{
	if((n&(-n))==n)
	{
		puts("YES");
		for(int i=n-2;i>=1;--i) printf("%d ",i);
		printf("%d %d\n",n,n-1);
	}
	else
	while(1)
	{
		for(int i=1;i<=n;++i) in[i]=1;
		int b=1; while(b<n) b<<=1;
		for(int i=n;i;i--)
		{
			//g(~i)&(b-1)
			int up=(~i)&(b-1);
			for(int j=up;j;j=(j-1)&up)
				if(in[j]) {a[i]=j; in[j]=0; break;}
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i]," \n"[i==n]);
		break;
	}
	}
	else puts("NO");
	
	int m = n - 1, chk = 0; if(n > 5 && (m & -m) == m) chk = 1, n -= 2;
	while(clock()<CLOCKS_PER_SEC*0.5)
	{
		set<pair<int,int> > gg;
		gg.clear();
		for(int i=1;i<=n;++i) gg.insert(make_pair(rand()*233333+rand(),i));
		for(int i=1;i<=n;++i)
		{
			int pp=0;
			for(auto g:gg)
				if(g.sec!=i&&(g.sec&i)) {pp=g.sec; gg.erase(g); break;}
			if(pp==0) goto MMMP;
			a[i]=pp;
		}
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		if(chk) printf("%d %d", n + 2, n + 1); puts("");
		exit(0); MMMP:;
	}
	puts("NO");
}