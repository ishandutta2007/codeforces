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
	int n;
	ll k;
	cin>>n>>k;
	cout<<(((n*6)-1)*k)<<endl;
	ll j = 1;
	FOR(i,0,n){
		cout<<k*j<<" "<<k*(j+1)<<" "<<k*(j+2)<<" "<<k*(j+4)<<endl;
		j += 6;
	}
}