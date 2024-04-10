#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int MAXN=7;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 1e9+7;

ll N,R,K,a,b,c;
vi A,B,C;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	while(N--){
		cin>>a>>b>>c;
		c-=b;
		c=c/a*a;
		cout<<c+b<<'\n';
	}
}