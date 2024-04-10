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

int N;
int fw[MAXN];

void update(ll x, ll v) {
    for (; x<=N; x+=x&(-x)) fw[x] += v; 
}

ll sum(ll x) {
    ll res = 0;
    for(; x; x-=x&(-x)) res += fw[x];
    return res;
}

int A[MAXN];
int B[MAXN];
int ind[MAXN];
vpi V;

int main(){
	cin>>N;
	for (int i=N;i>=1;--i){
		cin>>A[i];
	}
	for (int i=N;i>=1;--i){
		cin>>B[i];
		ind[B[i]] = i;
	}
	for (int i=1;i<=N;++i)update(i,1);
	int ans=0;
	for (int i=1;i<=N;++i){
		int v = A[i];
		// cout<<"Value "<<v<<'\n';
		int in = ind[v];
		// cout<<"Index "<<in<<'\n';
		update(in,-1);
		int q = sum(N) - sum(in - 1);
		int l = (N- i);
		if (q!=l)++ans;
		// int l = 
		
	}
	cout<<ans;
}