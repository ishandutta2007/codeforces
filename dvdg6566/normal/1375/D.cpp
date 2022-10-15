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
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=1010;
const int MAXK=16;
const int INF = 1e9;
const ll MOD = 1e9+7;
ll A[MAXN];
ll B[MAXN];
vi res;
ll N,Q;

int getmex(){
	for(int i=0;i<=N;++i)if(B[i]==0)return i;
	return N;
}

int main(){
	cin>>Q;
	while(Q--){
		cin>>N;
		for(int i=0;i<=N;++i)B[i]=0;
		for(int i=0;i<N;++i){
			cin>>A[i];
			B[A[i]]++;
		}
		res.clear();
		for(int i=1;i<=2*N;++i){
			// for(int j=0;j<N;++j)cout<<A[j]<<' ';cout<<'\n';
			int fail=0;
			for(int j=0;j<N-1;++j)if(A[j]>A[j+1])fail=1;
			if(fail==0)break;
			int k=getmex();
			if(k!=N){
				B[A[k]]--;
				A[k]=k;
				B[k]++;
				res.pb(k);
			}else{
				int zt=-1;
				for(int j=0;j<N;++j)if(A[j]>j)zt=j;
				B[A[zt]]--;
				B[N]++;
				A[zt]=N;
				res.pb(zt);
			}
		}
		cout<<SZ(res)<<'\n';
		for(auto t:res)cout<<t+1<< ' ';cout<<'\n';
	}

}