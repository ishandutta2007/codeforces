#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
ll MOD = 1e9+7;
ll INF = 1e9;

ll a,b,c,d;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>a>>b>>c>>d;
	if (a > b)swap(a,b);
	if (b > c)swap(b,c);
	if (a > b)swap(a,b);
	cout<<max(0LL, a-(b-d)) +max(0LL, (b+d)-c);
}