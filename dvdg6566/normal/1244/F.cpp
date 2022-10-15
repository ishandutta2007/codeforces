#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define INF 1e9
#define MAXL 20

int N,K;
int A[MAXN];
int B[MAXN];
string S;
char O[MAXN];
vi V;

int main(){
	cin>>N>>K>>S;
	for (int i=1;i<=N;++i)A[i] = (S[i-1] == 'B');
	A[0] = A[N];
	A[N+1] = A[1];
	for (int i=1;i<=N;++i){
		if (A[i] == A[i+1] || A[i] == A[i-1])B[i] = 1;
		else B[i] = 0;
	}
	// for (int i=1;i<=N;++i)cout<<B[i]<<' ';cout<<'\n';
	V.pb(-INF);
	for (int i=1;i<=N;++i)if(B[i] == 1){
		V.pb(i);
	}
	V.pb(INF);
	if (SZ(V) == 2){
		if (K%2 == 0)cout<<S;
		else {
			for (auto i : S)cout<<(char)('B' + 'W' - i);
		}
		return 0;
	}
	for (int i=1;i<=N;++i){
		O[i] = 'A';
		if (B[i] == 1){
			O[i] = S[i-1];
		}else{
			int mindist = MAXN*2;
			int d = -1;
			auto x = lb(ALL(V), i);
			if (abs(i - *x) < mindist){
				mindist = abs(i-*x);
				d = S[*x-1];
			}
			--x;
			if (abs(i - *x) < mindist){
				mindist = abs(i-*x);
				d = S[*x-1];
			}
			int fst = V[1];
			// cout<<"Distance to first "<<N-i+fst<<'\n';
			if (N - i + fst < mindist){
				mindist = N - i + fst;
				d = S[fst-1];
			}
			// cout<<"Closest to "<<i<<" is "<<mindist<<'\n';
			int lst = V[SZ(V) - 2];
			if (N - lst + i < mindist){
				mindist = N-lst+i;
				d = S[lst-1];
			}
			if (mindist > K){
				if (K%2 == 0)O[i] = S[i-1];
				else O[i] = (char)('B' + 'W' - S[i-1]);
			}else{
				O[i] = d;
			}
		}
		cout<<O[i];
	}
}