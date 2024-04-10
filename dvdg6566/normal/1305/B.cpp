#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 300100;

ll T,Q,N,M,a,b,c,d,e,f;
ll A[MAXN];
ll B[MAXN];
vi V;
string S;
vi open, close;
int blk[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>S;
	N=SZ(S);
	for (int i=0;i<N;++i){
		if (S[i] == '(')open.pb(i+1);
		else close.pb(i+1);
	}
	reverse(ALL(open));
	// for (auto i : open)cout<<i<<' ';cout<<'\n';
	// for (auto i : close)cout<<i<<' ';cout<<'\n';
	vi out;
	while (SZ(open) && (SZ(close))){
		int t = open.back();open.pop_back();
		int r = close.back();close.pop_back();
		if (r < t)break;
		out.pb(r);out.pb(t);
	}
	if (SZ(out) == 0)cout<<"0\n";
	else{
		cout<<"1\n";
		sort(ALL(out));
		cout<<SZ(out)<<'\n';
		for (auto i : out)cout<<i<<' ';
	}
}