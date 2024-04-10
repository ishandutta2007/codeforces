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
#define MAXN 310000
#define MAXL 18

int m[15];
int a,b;

int main(){
	cin>>a>>b;
	for (int i=a;i<=b;++i){
		int x=i;
		memset(m,0,sizeof(m));
		bool ok = 1;
		while(x){
			if(m[x%10]){ok=0;break;}
			m[x%10]++;
			x /= 10;
		}
		if(ok){cout<<i;return 0;}
	}
	cout<<-1;
}