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
#define MAXN 1000100

ll N,a,b,c,d,e,f,E;
ll A[MAXN];
ll B[MAXN];
ll MOD =1e9+7;
ll ans,cnt,sub;
string S;

int main(){
	cin>>N>>S;
	int l=0;
	int r=0;
	for (auto i : S){
		if (i == 'L')++l;
		else ++r;
	}
	cout<<l+r+1;
}