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
#define MAXN 1010

ll N,K,E,Q,a,b,c,d,t,ans,cnt;
ll odd, even;
pi A[MAXN];

int main(){
	cin>>N;
	for (ll i=1;i<=N;++i){
		cin>>a>>b;
		a += 2000000;
		b += 2000000;
		assert(a>0&&b>0);
		A[i] = mp(a,b);
	}
	while(1){
		ll oo=0;
		ll oe=0;
		ll eo=0;
		ll ee=0;
		for (ll i=1;i<=N;++i){
			int a = A[i].f%2;
			int b = A[i].s%2;
			if (a == 1&&b==1)oo++;
			else if(a)oe++;
			else if (b)eo++;
			else ee++;
		}
		if (oe+eo > 0 && ee+oo > 0){
			assert(ee+oo>0 && ee+oo<N);
			cout<<ee+oo<<'\n';
			for (ll i=1;i<=N;++i){
				int a = A[i].f%2;
				int b = A[i].s%2;
				if (a == b){cout<<i<<' ';++c;}
			}
			assert(c==ee+oo);
			return 0;
		}
		if (oe+eo==0){
			// cout<<"HI\n";
			if (ee == 0){
				for (ll i=1;i<=N;++i){++A[i].f;++A[i].s;}
				continue;
			}else if (oo == 0){
				for (int i=1;i<=N;++i){A[i].f /= 2;A[i].s /= 2;}
				continue;
			}else{
				assert(ee>0&&ee<N);
				cout<<ee<<'\n';
				for (ll i=1;i<=N;++i){
					// cout<<A[i].f<<' '<<A[i].s<<'\n';
					int a = A[i].f%2;
					int b = A[i].s%2;
					if (a==0&&b==0){cout<<i<<' ';++c;}
				}
				assert(c==ee);
				return 0;
			}
		}else{
			assert(oo+ee==0);
			for (int i=1;i<=N;++i)++A[i].f;
		}
	}
}