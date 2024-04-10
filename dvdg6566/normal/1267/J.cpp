#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define MAXN 2000100
#define MAXL 17
#define INF 1e9
int N;

int A[MAXN];
int a,T;
vi V;

int solve(int x, int p){
	int small = (p-x%p)%p;
	x -= small * (p-1);
	if (x<0)return -1;
	return small + x/p;
}

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for (int i=1;i<=N;++i){
			cin>>a;
			A[a]++;
		}
		V.clear();
		int ans = MAXN;
		int minele = MAXN;
		for (int i=1;i<=N;++i){
			if (A[i]){
				minele=min(minele,A[i]+1);
				V.pb(A[i]);
			}
		}
		// for (auto i : V)cout<<i<<' ';cout<<'\n';
		for (int i=1;i<=minele+1;++i){
			int cur = 0;
			for (auto x : V){
				int t = solve(x,i);
				if (t==-1){cur=-1;break;}
				cur += t;
			}
			if (cur!=-1)ans = min(ans,cur);
		}
		cout<<ans<<'\n';
		for (int i=1;i<=N;++i)A[i]=0;
	}
}