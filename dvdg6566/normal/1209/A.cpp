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
#define SZ(x) (int)x.size()
#define MAXN 5000000

vi A,B;
int N,a,b;

int main(){
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>a;
		A.pb(a);
	}
	sort(ALL(A));
	A.resize(unique(ALL(A)) - A.begin());
	for (auto i : A){
		bool in = 1;
		for (auto x : B){if(i%x == 0)in = 0;}
		if (in){
			B.pb(i);
		}
	}
	cout<<SZ(B);
}