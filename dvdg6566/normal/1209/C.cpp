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
#define MAXN 210000
#define MAXL 18

vi A,B,C;
int N,a,b,T;
string S;

int main(){
	cin>>T;
	while(T--){
		cin>>N>>S;
		A.clear();
		for (auto i : S)A.pb(i-'0');
		int done = 0;
		for (int x=0;x<10;++x){
			if(done)break;
			B.clear();
			C.clear();
			for (auto p : A){
				if (p < x)B.pb(p);
				else if (p > x)C.pb(p);
			}
			int work = 1;
			for (int i=0;i<SZ(B)-1;++i)if(B[i] > B[i+1])work = 0;
			for (int i=0;i<SZ(C)-1;++i)if(C[i] > C[i+1])work = 0;
			if (work == 0)continue;
			int lastb = -1;
			for (int i=N-1;i>=0;--i)if(A[i] < x){lastb = i;break;}
			int fstb = N;
			for (int i=0;i<N;++i)if(A[i] > x){fstb = i;break;}

			for (int i=fstb+1;i<lastb;++i)if(A[i] == x)work = 0;
			if (work == 0)continue;
			done = 1;
			for (int i=0;i<N;++i){
				if (A[i] < x)cout<<1;
				else if (A[i] > x)cout<<2;
				else if (i > lastb)cout<<1;
				else cout<<2;
			}
			cout<<'\n';
		}
		if (!done)cout<<"-\n";
	}
}