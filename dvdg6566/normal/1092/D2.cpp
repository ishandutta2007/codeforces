#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 200010
int INF = 1e9;

vector<pii> V;
set<pi> S;
int N,a,c,r;
int p[MAXN];
int val[MAXN];
int len[MAXN];

int par(int x){return (x == p[x]) ? x:p[x] = par(p[x]);}

int main(){
	// freopen("in.txt","r",stdin);

	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>a;
		if (a == c){
			++r;
			continue;
		}else{
			if (c){
				int p = i-r;
				V.pb(mp(c, mp(p, i-1)));
			}
			c = a;
			r = 1;
		}
	}
	val[0] = val[N+1] = INF;
	p[N+1] = N+1;

	V.pb(mp(a, mp(N-r+1, N)));

	for (auto i : V){
		for (int j=i.s.f;j<=i.s.s;++j){
			p[j] = i.s.s;
		}
		val[i.s.s] = i.f;
		len[i.s.s] = i.s.s-i.s.f +1;
		S.insert(mp(i.f, i.s.s));
	}

	while(SZ(S) > 1){
		// for (int i=1;i<=N;++i)cout<<p[i]<<' '<<len[i]<<'\n';cout<<'\n';
		pi x = *S.begin();
		S.erase(x);
		if (len[x.s]%2 == 1){
			// Odd number in the lowest
			cout<<"NO";
			return 0;
		}
		int r = x.s;
		int l = x.s - len[x.s] + 1;

		int leftval = val[l-1];
		int rgtval = val[par(r+1)];

		if (leftval < rgtval){
			// We merge into the left side
			S.erase(mp(leftval,l-1 ));
			p[l-1] = r;
			len[r] += len[l-1];
			S.insert(mp(leftval, r));
			continue;
		}

		if (leftval == rgtval){
			// We merge both sides
			S.erase(mp(leftval, l-1));
			S.erase(mp(rgtval, par(r+1)));
			int newend = par(r+1);
			int newlen = len[newend] + len[r] + len[l-1];
			len[newend] = newlen;
			p[r] = p[l-1] = newend;
			S.insert(mp(leftval, newend));
			continue;
		}

		if (leftval > rgtval){
			// We merge into the right side
			int newend = par(r+1);
			S.erase(mp(rgtval, p[r+1]));
			p[r] = newend;
			len[newend] += len[r];
			S.insert(mp(rgtval, newend));
			continue;
		}
	}
	cout<<"YES";
}