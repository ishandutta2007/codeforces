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
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 5010;

int T,N,K;
int A[MAXN];
int lyr[MAXN];
int cnt;
int p[MAXN];
int nd[MAXN];
stack<int> rv;

int main(){
	cin>>T;
	while (T--){
		cin>>N>>K;
		while (SZ(rv))rv.pop();
		memset(A,0,sizeof(A));
		memset(nd,0,sizeof(nd));
		memset(p,0,sizeof(p));
		int curdepth = 0;
		cnt = 0;
		lyr[1] = 0;
		nd[0] = 1;
		for (int i=2;i<=N;++i){
			p[i] = i/2;
			lyr[i] = lyr[p[i]] + 1;
			cnt += lyr[i];
			curdepth = max(curdepth, lyr[i]);
			if (nd[lyr[i]] == 0){nd[lyr[i]] = i;}
			else rv.push(i);
		}
		if (cnt > K){
			cout<<"NO\n";
			continue;
		}
		while (cnt < K && SZ(rv)){
			int t = rv.top();rv.pop();
			int h = lyr[t];
			int inc = curdepth + 1 - h;
			if (cnt + inc <= K){
				p[t] = nd[curdepth];
				cnt += inc;
				curdepth++;
				nd[curdepth] = t;
			}else{
				int tar = nd[K - cnt + h-1];
				p[t] = tar;
				cnt = K;
				break;
			}
		}
		if (cnt < K){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for (int i=2;i<=N;++i)cout<<p[i]<<' ';cout<<'\n';
		// for (int i=0;i<=N;++i)cout<<nd[i]<<' ';cout<<'\n';
	}
}