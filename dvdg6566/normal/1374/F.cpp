#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
const int MAXN=7;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 1e9+7;

ll N,R,K,a,b,c;
vi A,B,C;
map<int,int> M;

void op(int in){
	// cerr<<in<<'\n';
	B.pb(in);
	int a=A[in];
	int b=A[in+1];
	int c=A[in+2];
	A[in]=c;
	A[in+1]=a;
	A[in+2]=b;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>R;
	while(R--){
		cin>>N;B.clear();
		A.clear();
		A.pb(-1);
		for(int i=0;i<N;++i){cin>>a;A.pb(a);}
		int inv=0;
		for(int i=1;i<=N;++i)for(int j=i;j<=N;++j){
			if(A[i]>A[j])++inv;
		}
		vpi des;
		for(int i=1;i<=N;++i)des.pb(A[i],i);
		sort(ALL(des));
		int flip=inv%2;
		for (int i=0;i<N-1;++i){
			if(des[i].f!=des[i+1].f)continue;
			if(flip){
				swap(des[i],des[i+1]);
				flip=0;
				break;
			}
		}
		// cout<<flip<<'\n';
		for(int i=0;i<SZ(des);++i){
			A[des[i].s]=i+1;
		}
		// for(int i=1;i<=N;++i)cout<<A[i]<<' ';cout<<'\n';
		inv=0;
		for(int i=1;i<=N;++i)for(int j=i;j<=N;++j){
			if(A[i]>A[j])++inv;
		}
		// cout<<inv<<'\n';
		if(inv%2==1){
			cout<<-1<<'\n';
			continue;
		}

		for(int i=1;i<=N-2;++i){
			int ind=0;
			for(int j=1;j<=N;++j)if(A[j]==i){ind=j;break;}
			int tar=i;
			while(ind>=tar+2){
				// call ind-2
				ind-=2;
				op(ind);
			}
			if(ind!=tar){
				assert(ind-1==tar);
				op(ind-1);
				op(ind-1);
			}
			// for(int i=1;i<=N;++i)cout<<A[i]<<' ';cout<<'\n';
			// cout<<tar<<' '<<ind<<'\n';
		}
		assert(SZ(B)<=N*N);
		cout<<SZ(B)<<'\n';
		for(auto t:B)cout<<t<<' ';cout<<'\n';
	}
}