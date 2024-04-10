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
vi occ[MAXN];
int lwst[MAXN];

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		V.clear();des.clear();
		for(int i=1;i<=N;++i){
			cin>>A[i];
			des.pb(A[i]);
			V.pb(A[i],i);
		}
		for(int i=0;i<=N;++i){
			lwst[i]=0;
			occ[i].clear();
		}
		sort(ALL(des));des.resize(unique(ALL(des))-des.begin());
		for(int i=1;i<=N;++i){
			A[i]=lb(ALL(des),A[i])-des.begin();
			occ[A[i]].pb(i);
		}
		int ans=N;

		// For each one, find the furthest u can go by taking the entire thing
		for(int i=SZ(des)-1;i>=0;--i){
			lwst[i]=SZ(occ[i]);
			if(SZ(occ[i+1]) && occ[i].back() <= occ[i+1][0]){
				lwst[i]=SZ(occ[i]) + lwst[i+1];
			}
			int ltst = occ[i].back();
			for(int t=0;t<SZ(occ[i+1]);++t){
				int x=occ[i+1][t];
				if(x<ltst)continue;
				lwst[i] = max(lwst[i], SZ(occ[i]) + SZ(occ[i+1]) - t);
			}
			ans=min(ans,N-lwst[i]);
			// cerr<<des[i]<<' '<<lwst[i]<<'\n';
		}
		// Starting with a prefix
		for(int i=0;i<SZ(des)-1;++i){
			// cerr<<"Desed "<<des[i]<<'\n';
			// cerr<<"Abv "<<lwst[i+1]<<'\n';
			assert(SZ(occ[i+1]));
			for(int t=0;t<SZ(occ[i]);++t){
				if(occ[i+1][0] < occ[i][t])continue;
				// cerr<<lwst[i+1]+(t+1)<<'\n';
				// cerr<<"Aind "<<occ[i+1][0]<<" cind "<<occ[i][t]<<'\n';
				ans=min(ans, N-lwst[i+1]-(t+1));
			}
		}


		// Edge case: only using 2 occurences
		for(int i=0;i<SZ(des)-1;++i){
			vi A,B;
			for(auto i:occ[i])A.pb(i);
			for(auto i:occ[i+1])B.pb(i);
			reverse(ALL(B));
			int k=SZ(B);
			for(auto i:A){
				++k;
				while(SZ(B) && B.back() < i){
					B.pop_back();
					--k;
				} 
				ans=min(ans,N-k);
			}
		}
		cout<<ans<<'\n';
	}
}