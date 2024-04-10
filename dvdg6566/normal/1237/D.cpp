#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 310000
#define INF 1e9
#define MAXL 20

int A[MAXN], N;
int B[MAXN];

struct MaxSparseTable {
    vector<vector<int> > ST;
    int N, K;
    MaxSparseTable(int _N): N(_N) {
        K = MSB(N);
        ST.resize(K);
        ST[0] = vector<int>(A, A+N);
        for (int k = 1; k < K; ++k) 
            for (int i = 0; i+(1<<k) <= N; ++i) 
                ST[k].push_back( max(ST[k-1][i], ST[k-1][i+(1<<(k-1))]) ); //min
    }
    
    /* returns most significant bit of an integer */
    inline int MSB(unsigned int x) { return 32-__builtin_clz(x); }
    
    /* Min of range (x, x + 2^k-1) and (y-2^k+1, y) */
    int query(int x, int y) {
  		if (y<x)return -INF;
        int k = MSB(y-x+1) - 1;
        return max(ST[k][x], ST[k][y-(1<<k)+1]);            //min
    }
}*MAXST;

struct MinSparseTable {
    vector<vector<int> > ST;
    int N, K;
    MinSparseTable(int _N): N(_N) {
        K = MSB(N);
        ST.resize(K);
        ST[0] = vector<int>(A, A+N);
        for (int k = 1; k < K; ++k) 
            for (int i = 0; i+(1<<k) <= N; ++i) 
                ST[k].push_back( min(ST[k-1][i], ST[k-1][i+(1<<(k-1))]) ); //min
    }
    
    /* returns most significant bit of an integer */
    inline int MSB(unsigned int x) { return 32-__builtin_clz(x); }
    
    /* Min of range (x, x + 2^k-1) and (y-2^k+1, y) */
    int query(int x, int y) {
    	if (y<x)return -INF;
        int k = MSB(y-x+1) - 1;
        return min(ST[k][x], ST[k][y-(1<<k)+1]);            //min
    }
}*MINST;

bool ok (int a, int b){
	if (a == b)return 1;
	int T = MAXST->query(a,b);
	// cout<<a<<' '<<b<<' '<<T<<'\n';
	if (a < T)return 0;
	return 1;
}

int main(){
	cin>>N;
	for (int i=0;i<N;++i)cin>>A[i];
	for (int i=0;i<N;++i)A[N+i] = A[2*N+i] = A[i];
	MAXST = new MaxSparseTable(3*N);
	MINST = new MinSparseTable(3*N);
	for (int i=1;i<3*N;++i){
		int s = 0;
		int e = i;
		while (e-s>1){
			int m = (e+s)/2;
			int H = MAXST->query(m,i-1);
			if (2*A[i] < H)s = m+1;
			else e = m;
		}
		if (s != e){
			int H = MAXST->query(s,i-1);
			if (2*A[i] < H)s = e;
		}
		B[i] = s;
	}
	swap(A,B);
	MAXST = new MaxSparseTable(3*N);
	for (int i=0;i<N;++i){
		int s = i;
		int e = i+2*N-1;
		while(e-s>1){
			int m = (s+e)/2;
			if (ok(i,m))s = m;
			else e = m-1;
		}
		// cout<<s<<' '<<e<<'\n';
		if (s!=e){
			if (!ok(i,e))e = s;
		}
		if (e-i+1 == 2*N)cout<<-1<<'\n';
		else cout<<(e-i+1)<<'\n';
	}
}