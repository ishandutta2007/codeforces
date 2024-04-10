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
const int MAXN=200110;
const ll MOD=998244353;

int N,T,M;
int A[MAXN];
vpi V;
int nx[MAXN];
int ht[MAXN];

int askht(int x){
	if(nx[x] == -1)return ht[x]=1;
	if(ht[x]!=-1)return ht[x];
	return askht(nx[x])+1;
}

// bool cmp(pi a,pi b){
// 	if(a.f==b.f)return a.s<b.s;
// 	return a.f<b.f;
// }

int mxh[MAXN];
int mxh2[MAXN];
vi des;
int fstind[MAXN];

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		V.clear();des.clear();
		for(int i=1;i<=N;++i){
			cin>>A[i];
			des.pb(A[i]);
			V.pb(A[i],i);
			ht[i]=1;
			nx[i]=-1;
			fstind[i]=-1;
		}
		sort(ALL(des));des.resize(unique(ALL(des))-des.begin());
		for(int i=1;i<=N;++i){
			A[i]=lb(ALL(des),A[i])-des.begin()+1;
			mxh[A[i]]=mxh[A[i]+1]=0;
			mxh2[A[i]]=mxh2[A[i]+1]=0;
		}
		for(int i=N;i>=1;--i)fstind[A[i]]=i;
		sort(ALL(V));

		for(int i=SZ(V)-2;i>=0;--i){
			int a=V[i].s;
			int b=V[i+1].s;
			if(b>a){
				ht[a]=max(ht[a], ht[b]+1);
			}
		}

		int ans=N;
		for(int a=N;a>=1;--a){
			int t=ht[a];
			// cerr<<"First of "<<des[A[a]-1]<<" is "<<des[A[a]]<<' '<<fstind[A[a]+1]<<'\n';

			// if(fstind[A[a]+1] > a){
				// cerr<<"First "<<A[a]+1<<'\n';
			t=max({t, 1+mxh[A[a]+1],mxh2[A[a]]+1 });
			// }
			// cerr<<des[A[a]-1]<<' '<<t<<'\n';
			ans=min(ans,N-t);

			mxh[A[a]] = max(mxh[A[a]],ht[a]);
			mxh2[A[a]] = max(mxh2[A[a]],t);
		}
		cout<<ans<<'\n';
	}
}