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
const ll MAXN = 210000;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,a;
vpi V;

int ask(int X){
	ll Y =X;
	if(X==1)return 2;
	if(X%2==1)return 1;
	X /= 2;
	for (int i=2;i<100000;++i)if(X%i==0){
		V.pb(i,0);
		while(X%i==0){
			++V.back().s;
			X/=i;
		}
	}
	if(X == 1){
		if(SZ(V)==1 && V[0].f == 2){
			return 2;
		}else if (SZ(V) == 1 && V[0].f*2 == Y){
			return 2;
		}
	}
	else if(SZ(V)==0)return 2;
	return 1;
}

int main(){
	cin>>N;
	while(N--){
		V.clear();
		cin>>a;
		if(ask(a)==2){
			cout<<"FastestFinger\n";
		}else{
			cout<<"Ashishgup\n";
		}
	}
}