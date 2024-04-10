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
#define SZ(x) (int)x.size()
#define MAXN 210000
#define MAXL 18

ll T,N;
string S;
int zeroes[MAXN];

int main(){
	cin>>T;
	while(T--){
		cin>>S;
		N = SZ(S);
		for (int i=1;i<N;++i){
			if (S[i-1] == '1')zeroes[i] = 0;
			else zeroes[i] = zeroes[i-1] + 1;
		}
		ll ans=0;
		for (int i=0;i<N;++i){
			if (S[i] == '0')continue;
			int curval = 1;
			int curlen = zeroes[i]+1;
			++ans;
			for (int j=i+1;j<N;++j){
				curval *= 2;
				curval += S[j] - '0';
				curlen++;
				if (curval <= curlen)++ans;
				if (curval > curlen && curlen > 10)break;
			}
		}
		cout<<ans<<'\n';
	}
}