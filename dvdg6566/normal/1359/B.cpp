#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 100100;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,K,W,T,a,b,c,d,e;
ll R,C;

int main(){
	cin>>T;
	while(T--){
		cin>>R>>C>>a>>b;
		c=d=0;
		string S;
		for(int i=0;i<R;++i){
			cin>>S;
			S+='*';
			int cnt=0;
			for (auto i:S){
				if(i=='.')++cnt;
				else{
					c+=cnt%2;
					d+=cnt/2;
					cnt=0;
				}
			}
		}
		if(a*2<=b){
			cout<<(d*2+c)*a<<'\n';
		}else{
			cout<<d*b+a*c<<'\n';
		}
	}
}