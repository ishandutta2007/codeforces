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
#define MAXN 1010000
#define MAXL 18

int Q,N;
int R,a;
vi V;

int main(){
	cin>>Q;
	while (Q--){
		cin>>N>>R;
		for (int i=1;i<=N;++i){
			cin>>a;
			V.pb(a);
		}
		sort(ALL(V));
		int ans=0;
		int off=0;
		while(SZ(V)){
			int t = V.back();
			while(SZ(V) && V.back() == t)V.pop_back();
			++ans;
			off += R;
			while (SZ(V) && V.back() <= off)V.pop_back();
		}
		cout<<ans<<'\n';
	}
}