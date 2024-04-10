#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

//2d fenwick tree, 1-indexed
template <class T>
struct bit_2d {
	int N,M;
	vector<vector<T>> b;

	void init(int n, int m){N=n+1,M=m+1,b=vector<vector<T>>(N,vector<T>(M));}
	bit_2d(){}
	bit_2d(int n, int m){init(n,m);}

	inline void update(int i, int j, T v) {
		for(;i < N; i += i&-i)
			for(int k = j; k < M; k += k&-k)
				b[i][k] += v;
	}

	//xor of the 'prefix' i x j rectangle
	inline T prefix(int i, int j) {
		T a = 0;
		for(;i;i ^= i&-i)
			for(int k = j;k;k ^= k&-k)
				a += b[i][k];
		return a;
	}

	inline T query(int a, int b, int c, int d) {
		return prefix(c,d)+prefix(a-1,b-1)-prefix(a-1,d)-prefix(c,b-1);
	}
};

map<vector<int>,ll> M;
int main() {
	srand(time(0));
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	bit_2d<ll> B(n+1,m+1);
	while(q--) {
		int t,a,b,c,d;
		scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
		if(t == 3) {
			if(B.prefix(a,b) == B.prefix(c,d))
				printf("Yes\n");
			else printf("No\n");
		} else {
			ll r;
			if(t == 1) {
				r = rand();
				r = (r<<16)^rand();
				r = (r<<16)^rand();
				r = (r<<16)^rand();
				M[vector<int>({a,b,c,d})] = r;
			} else {
				r = -M[vector<int>({a,b,c,d})];
			}
			B.update(a,b,r);
			B.update(a,d+1,-r);
			B.update(c+1,b,-r);
			B.update(c+1,d+1,r);
		}
	}
}