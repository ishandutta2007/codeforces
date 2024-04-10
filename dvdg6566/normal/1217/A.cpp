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

int N,E,P,Q,M;
int A,B,C;

int main(){
	cin>>N;
	while(N--){
		cin>>A>>B>>C;
		int dif = A+C-B;
		cout<<min(C+1, max(0, (dif+1)/2))<<'\n';
	}
}