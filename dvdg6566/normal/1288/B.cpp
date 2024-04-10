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


int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>a>>b;
		ll t = 9;
		ll r = 0;
		while (b >= t){
			++r;
			t = 10*t+9;
		}
		cout<<r*a<<'\n';
	}
}