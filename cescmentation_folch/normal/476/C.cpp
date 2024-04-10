#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<stack>
#include<iomanip>

using namespace std;

#define X first
#define Y second
#define FOR(i,a,f) for(int i = a;i < f;++i)
#define ROF(i,a,f) for(int i = a;i > f;--i)


typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<int, int> PI;
typedef pair<bool , int> PBI;
typedef pair<PI,PBI> PIB;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef priority_queue<PI> PQPI;
typedef queue<PI> QPI;
typedef queue<PIB> QPIB;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<VC> VVC;

int main(){
	ll mod = 1e9+7;
	ll a,b;
	cin>>a>>b;
	ll ar = (a*(a+1)/2)%mod;
	ll br = (b*(b-1)/2)%mod;
	ll res = (ar*br)%mod;
	res = (res*b)%mod;
	res = (res+(a*br))%mod;
	cout<<res<<endl;
}