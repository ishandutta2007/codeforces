#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

#define X first
#define Y second
#define rep(i,a,f) for(int i = a;i < f;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<string, string> PS;
typedef vector<PS> VPS;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

int mod = 1e9+7;

VI R((int)1e5+1,-1);

int k;

int f(int i){
	if(i == 0) return 1;
	if(i < 0) return 0;
	if(R[i] > 0) return R[i];
	return R[i] = (f(i-1)+f(i-k))%mod;
}

int main(){
	int t;
	cin>>t>>k;
	f((int)1e5);
	R[0] = 0;
	for(int i = 1;i <= (int)1e5;++i){
		R[i] = (R[i]+R[i-1])%mod;
	}
	for(int i = 0;i < t;++i){
		int a,b;
		cin>>a>>b;
		cout<<(R[b]-R[a-1]+mod)%mod<<endl;
	}
}