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
#define forl(i,a,f) for(int i = a;i < f;++i)
#define rofl(i,a,f) for(int i = a;i > f;--i)
#define pb push_back


typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<ll ,ll> Pll;
typedef vector<Pll> VPll;
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
	ll a,b;
	cin>>a>>b;
	if(a%2 == 0 && b-2 >= a) cout<<a<<" "<<a+1<<" "<<a+2<<endl;
	else if(a%2 == 1 && b-2 > a) cout<<a+1<<" "<<a+2<<" "<<a+3<<endl;
	else cout<<"-1"<<endl;
}