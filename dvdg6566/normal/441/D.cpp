#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=101000;
const ll MOD=998244353;
const int MAXL = 8000100;
const ll INF = 1e18;

int N,M;
int p[MAXN];
int A[MAXN];
int par(int x){return(p[x]==x)?x:p[x]=par(p[x]);}

void mv(int a,int b){
	cout<<a<<' '<<b<<'\n';
	swap(A[a],A[b]);
	for(int i=1;i<=N;++i)p[i]=i;
	for(int i=1;i<=N;++i){
		int a=par(A[i]);
		int b=par(i);
		if(a!=b)p[a]=b;
	}
}

int main(){
	cin>>N;
	for(int i=1;i<=N;++i)cin>>A[i];
	cin>>M;
	for(int i=1;i<=N;++i)p[i]=i;
	for(int i=1;i<=N;++i){
		int a=par(A[i]);
		int b=par(i);
		if(a!=b)p[a]=b;
	}
	int cnt=0;
	for(int i=1;i<=N;++i)if(par(i)==i)++cnt;
	int grps=N-cnt;
	if(grps<=M){
		cout<<M-grps<<'\n';
		int cn=2;
		for(int i=0;i<M-grps;++i){
			while(par(cn) == par(1))++cn;
			p[par(cn)]=par(1);
			cout<<1<<' '<<cn<<' ';
		}
	}else{
		cout<<grps-M<<'\n';
		int cn=1;
		for(int i=0;i<grps-M;++i){
			while(A[cn]==cn)++cn;
			int tx=-1;
			for(int j=cn+1;j<=N;++j)if(par(j) == par(cn)){
				tx=j;
				break;
			}
			mv(cn,tx);
		}
	}
}