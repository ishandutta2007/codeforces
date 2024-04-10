
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
const int MAXN=310000;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 998244353;
 
vi V[MAXN];
ll N,a,b,c,d,T,Q,M,x,y,z,u,v,w;
ll A[MAXN];
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		string S;
		cin>>S;
		stack<int> st;
		b=0;
		for(auto i:S){
			a=i-'0';
			if(!SZ(st)||st.top()==a)st.push(a);
			else {
				st.pop();
				++b;
			}
		}
		if(b%2)cout<<"DA\n";
		else cout<<"NET\n";
		// cout<<b<<'\n';
	}
}