#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAXN 101000
ll N,a,b;

bool ask(int a, int b){
	for (ll t = 0;t<=100000;++t){
		ll p = t+(a + t)/(t+1);
		// cout<<a<<' '<<t<<' '<<p<<'\n';
		if (p <= b)return 1;
	}
	return 0;
}

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>a>>b;
		if (ask(b,a))cout<<"YES\n";
		else cout<<"NO\n";
	}
}