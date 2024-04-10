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

ll N;
string A, B;


int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	while(N--){
		cin>>A>>B;
		int res = 0;
		while(SZ(A)){
			char c = A.back();
			int a=0;
			int b=0;
			while(SZ(A) && A.back() == c){
				++a;
				A.pop_back();
			}
			while(SZ(B) && B.back() == c){
				++b;
				B.pop_back();
			}
			if (b < a){
				cout<<"NO\n";
				res = 1;
				break;
			}
		}
		if (SZ(B) && !res){
			cout<<"NO\n";
			res = 1;
		}
		if (!res)cout<<"YES\n";
	}
}