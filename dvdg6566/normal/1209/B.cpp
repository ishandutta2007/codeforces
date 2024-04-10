#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18

int memo[200];

int cur,a,b;
string S;
int N;

int main(){
	cin>>N>>S;
	for (int i=0;i<N;++i){
		cin>>a>>b;
		cur = S[i] - '0';
		for (int j=0;j<150;++j){
			if (j >= b && (j-b)%a==0){
				cur = 1-cur;
			}
			memo[j] += cur;
		}
	}
	int ans = 0;
	for (int j=0;j<150;++j)ans = max(ans, memo[j]);
	cout<<ans;
}