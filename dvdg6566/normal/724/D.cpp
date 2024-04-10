#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 100100

bool D[MAXN];
vi I[MAXN];
int A[MAXN],B[MAXN];
int N,M,C;
string S;
multiset<ll> st;
vi V;

int main(){
	cin>>M>>S;
	N=SZ(S);
	for (int i=0;i<N;++i){
		int t = S[i] - 'a';
		A[i+1] = t;
		I[t].pb(i+1);
	}
	S="";
	for (int i=1;i<M;++i){
		st.insert(A[i]);
	}
	for (int i=1;i<=N;++i){
		if (i+M-1<=N)st.insert(A[i+M-1]);
		if (i>1)st.erase(st.find(A[i-1]));
		B[i] = *st.begin();
	}
	int T = 0;
	for (int i=1;i<=N-M+1;++i)T=max(T,B[i]);
	for (int i=0;i<T;++i){
		for (auto x:I[i]){
			S += (char)('a'+i);
			D[x]=1;	
		}
	}
	for (int i=1;i<=N-M+1;++i)if (B[i]==T){
		V.pb(i);
	}
	reverse(ALL(I[T]));
	reverse(ALL(V));
	// cout<<"V ";for (auto i:V)cout<<i<<' ';cout<<'\n';
	// cout<<"I ";for (auto i:I[T])cout<<i<<' ';cout<<'\n';
	int last = -1;
	while(SZ(V)){
		int t = V.back();
		V.pop_back();
		if (t+M-1>=last && t<=last)continue;
		while(SZ(I[T])){
			if (I[T].back() < t)I[T].pop_back();
			else break;
		}
		// cout<<SZ(I[T])<<'\n';
		while(SZ(I[T]) > 1){
			if (I[T][SZ(I[T]) - 2] <= t+M-1){
				I[T].pop_back();
			}else break;
		}
		// cout<<SZ(I[T])<<'\n';

		last = I[T].back();
		I[T].pop_back();
		S += (char)('a'+T);
	}
	cout<<S;
}